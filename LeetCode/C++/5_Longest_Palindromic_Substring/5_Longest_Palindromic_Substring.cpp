#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string appendS = "$#";
        for(auto t : s){
            appendS += t;
            appendS += "#";
        }
        
        vector<int> p(appendS.size(), 0);
        int mx = 0, id = 0, resLen = 0, resCenter = 0;
        for(int i = 1; i < appendS.size(); i++){
            p[i] = mx > i ? min(p[2*id - i], mx - i) : 1;
            while(appendS[i + p[i]] == appendS[i - p[i]])
                p[i]++;
            
            if(mx < i + p[i]){
                mx = i + p[i];
                id = i;
            }
            
            if(resLen < p[i]){
                resLen = p[i];
                resCenter = i;
            }
        }
        return s.substr((resCenter - resLen)/2, resLen - 1);
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
        string s = stringToString(line);
        
        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}