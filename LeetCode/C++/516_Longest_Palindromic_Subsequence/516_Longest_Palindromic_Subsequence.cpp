#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <assert.h>

using namespace std;

class Solution {
public:
    /*
     * 区间dp：常见递推公式：dp[i][j] = max{dp[i][k] + dp[k+1][j] + f(k, k+1), i<=k<j}
     * 问题为最长回文子序列而不是子串，具体还不太懂。
     */
    int longestPalindromeSubseq(string s) {
        if(s.empty())
            return 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i = 0; i < s.size(); i++)
            dp[i][i] = 1; 
        for(int len = 2; len <= s.size(); len++){
            for(int i = 0; i <= s.size() - len; i++){
                int j = len + i -1;
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0].back();
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
        
        int ret = Solution().longestPalindromeSubseq(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}