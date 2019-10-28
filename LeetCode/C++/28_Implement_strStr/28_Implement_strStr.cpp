#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
    int kmp(string &haystack, string &needle){
        vector<int> next(needle.size(), -1);
        int i = 0, j = -1;
        while(i < needle.size()-1){
            if(j == -1 || needle[i] == needle[j]){
                next[++i] = ++j;
            }else{
                j = next[j];
            }
        }

        i = j = 0;
        while(i < haystack.size() && j < static_cast<int>(needle.size())){
            if(j == -1 || haystack[i] == needle[j])
                i++, j++;
            else{
                j = next[j];
            }
        }
        return j == needle.size() ? i-j : -1;
    }

    int strStr(string haystack, string needle) {
        if(needle.size() == 0)
            return 0;
        return kmp(haystack, needle);
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string haystack = stringToString(line);
        getline(cin, line);
        string needle = stringToString(line);
        
        int ret = Solution().strStr(haystack, needle);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}