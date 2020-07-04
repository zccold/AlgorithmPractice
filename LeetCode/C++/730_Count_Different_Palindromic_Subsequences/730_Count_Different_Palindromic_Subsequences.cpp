#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <assert.h>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequences(string S) {
        if(S.empty())
            return 0;
        vector<vector<int>> dp(S.size(), vector<int>(S.size(), 0));
        for(int i = 0; i < S.size(); i++)
            dp[i][i] = 1; 
        for(int len = 2; len <= S.size(); len++){
            for(int i = 0; i <= S.size() - len; i++){
                int j = len + i - 1;
                if(S[i] == S[j]){
                    dp[i][j] = dp[i+1][j-1]*2;
                    int l = i + 1, r = j - 1;
                    while(l <= r && S[l] != S[i])
                        l++;
                    while(r >= l && S[r] != S[j])
                        r--;
                    // 例如：S[i, j] = aabaa，dp[i+1][j-1] = {a, b, aa, aba}, 
                    // dp[i][j] = dp[i+1][j-1] + {aaa, aba, aaaa, aabaa} - {aba}
                    if(l < r)
                        dp[i][j] -= dp[l+1][r-1];
                    // 例如：S[i, j] = ababa，dp[i+1][j-1] = {b, a, bb, bab}, 
                    // dp[i][j] = dp[i+1][j-1] + {aba, aaa, abba, ababa} + {aa}
                    else if(l == r)
                        dp[i][j] += 1;
                    // 例如：S[i, j] = aba，dp[i+1][j-1] = {b}, 
                    // dp[i][j] = dp[i+1][j-1] + {aba} + {a, aa}
                    else
                        dp[i][j] += 2;
                }else{
                    dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
                }
                // 由于dp[i][j]会不断对10^9+7取模，因此上述出现减法的地方有可能导致dp[i][j]为负。
                // 通过加上10^9+7可以抵消影响。
                dp[i][j] = dp[i][j] < 0 ? (dp[i][j] + 1000000007) : (dp[i][j]%1000000007);
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
        string S = stringToString(line);
        
        int ret = Solution().countPalindromicSubsequences(S);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}