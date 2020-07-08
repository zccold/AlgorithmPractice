#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    /*
     * 严格来说，题解并不是dp，只是将递归树型结构改为迭代，并缓存之前结果。
     */
    int findTargetSumWays(vector<int>& nums, int S) {
        if(S > 1000 || S < -1000)
            return 0;
        vector<vector<int>> dp(nums.size(), vector<int>(2001, 0));
        dp[0][nums[0] + 1000] = 1, dp[0][-nums[0] + 1000] += 1;
        int sum = 0;
        for(int i = 1; i < nums.size(); i++){
            sum += nums[i-1];
            for(int j = -sum; j <= sum; j++){
                dp[i][j+nums[i] + 1000] += dp[i-1][j + 1000];
                dp[i][j-nums[i] + 1000] += dp[i-1][j + 1000];
            }
        }
        return dp.back()[S + 1000];
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int S = stringToInteger(line);
        
        int ret = Solution().findTargetSumWays(nums, S);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}