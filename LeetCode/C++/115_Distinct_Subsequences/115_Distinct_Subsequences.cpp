#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /*
     * 这题很简单，思路来说的话，先是递归s的每个字符，每个字符有保留以及删除两种选择，这样得到一颗递归树，
     * 这样优化子结构与重叠子问题就出来了，接下来进行动态规划的优化。
     * 很容易联想到背包问题，然后得出递推方程
     * dp[i+1, j+1] = (s[i] == t[j]) ? (dp[i][j] + dp[i][j+1]) : dp[i][j+1]
     * 即当s[i] == t[j]，可以选择保留以及删除t[j]，否则，只能删除t[j]。
     * 
     * 接着进行空间优化
     */
    int numDistinct(string s, string t) {
        vector<long long> dp(t.size()+1, 0);
        dp[0] = 1;
        
        for(auto chs : s){
            for(int i = t.size()-1; i >= 0; i--){
                if(chs == t[i])
                    dp[i+1] += dp[i];
            }
        }
        return dp.back();
    }
};

void trimLeft(string& input){
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](char ch){
        return isspace(ch);
    }));
}

void trimRight(string& input){
    input.erase(find_if(input.rbegin(), input.rend(), [](char ch){
        return isspace(ch);
    }).base(), input.end());
}

int main() {
    string line;
    while (true) {
        getline(cin, line);
        trimLeft(line);
        trimRight(line);
        string s = line.substr(1, line.size()-2);

        getline(cin, line);
        trimLeft(line);
        trimRight(line);
        string t = line.substr(1, line.size()-2);

        int out = Solution().numDistinct(s, t);
        cout << out << endl;
    }
    return 0;
}