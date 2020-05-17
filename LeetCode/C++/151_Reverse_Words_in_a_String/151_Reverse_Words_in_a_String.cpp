#include <iostream>
#include <string>
#include <assert.h>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    ///
    /// Solution1: use stringstream
    ///
    // string reverseWords(string s) {
    //     if(s.empty())
    //         return s;
    //     stringstream ss(s);
    //     string item;
    //     char delim = ' ';
    //     string res;
    //     while(getline(ss, item, delim)){
    //         if(!item.empty())
    //             res = item + " " + res;
    //     }
    //     if(!res.empty())
    //         res.erase(res.size()-1);
    //     return res;
    // }

    ///
    /// Solution2: iterative by hand
    ///
    string reverseWords(string s){
        if(s.empty())
            return s;
        string res;
        int i = 0;
        while(i < s.size()){
            while(i < s.size() && isspace(s[i]))
                i++;
            int j = i;
            while(j < s.size() && !isspace(s[j]))
                j++;
            if(i < s.size())
                res = s.substr(i, j-i) + " " + res;
            i = j;
        }
        if(!res.empty())
            res.erase(res.size()-1);
        return res;
    }

    ///
    /// Solution3: first reverse(str), then reverse(word)
    ///
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
        string s = stringToString(line);
        
        string ret = Solution().reverseWords(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}