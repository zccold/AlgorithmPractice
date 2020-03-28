#include <assert.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        for(int i = 0; i < text1.size(); i++){
            for(int j = 0; j < text2.size(); j++){
                if(text1[i] == text2[j]){
                    dp[i+1][j+1] = dp[i][j]+1;
                }else if(dp[i][j+1] > dp[i+1][j]){
                    dp[i+1][j+1] = dp[i][j+1];
                }else{
                    dp[i+1][j+1] = dp[i+1][j];
                }
            }
        }
        return dp.back().back();
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
        string text1 = stringToString(line);
        getline(cin, line);
        string text2 = stringToString(line);
        
        int ret = Solution().longestCommonSubsequence(text1, text2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}