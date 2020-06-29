#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        //初始化word2.size() == 0时的编辑距离
        for(int i = 0; i < word1.size(); i++)
            dp[i+1][0] = i+1;
        //初始化word1.size() == 0时的编辑距离
        for(int j = 0; j < word2.size(); j++)
            dp[0][j+1] = j+1;
        //编辑距离=min(当前字符相等，当前字符不等(增、删、改)+1)
        for(int i = 0; i < word1.size(); i++){
            for(int j = 0; j < word2.size(); j++){
                dp[i+1][j+1] = min(min(dp[i][j+1], dp[i+1][j]) + 1, dp[i][j] + (word1[i] == word2[j] ? 0 : 1));
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
        string word1 = stringToString(line);
        getline(cin, line);
        string word2 = stringToString(line);
        
        int ret = Solution().minDistance(word1, word2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}