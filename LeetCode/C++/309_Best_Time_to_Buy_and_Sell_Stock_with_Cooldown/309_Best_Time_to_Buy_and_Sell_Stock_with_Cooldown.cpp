#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    /*
     * k = infinity, have cooldown = 1
     * 
     * dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
     * dp[i][k][1] = max(dp[i-1][k][1], dp[i-2][k-1][0] - prices[i])
     * 第i天可执行动作为什么也不做、买入、卖出；
     * 第i天状态为执行当天动作后完成了k次交易，目前持有或不持有股票。
     * 
     * 直观来看，dp[i][k][1]相当于前k-1次交易最大收益减去当前最低买入价，
     *          dp[i][k][0]相当于前k次交易最大收益；
     * 
     * dp[i][k-1][0] = dp[i][k][0], dp[i][k-1][1] = dp[i][k][1]，为什么？
     * 当k = infinity时，dp蜕化为贪婪算法，因此最佳策略在所有局部最优买入和卖出，
     * k和k-1都一定是所有局部最优个数。
     */
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        int dpik0 = 0, dpik1 = -prices[0], dpik0Old = 0;
        for(int i = 1; i < prices.size(); i++){
            dpik1 = max(dpik1, dpik0Old - prices[i]);
            dpik0Old = dpik0;
            dpik0 = max(dpik0, dpik1 + prices[i]);
        }
        return dpik0;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> prices = stringToIntegerVector(line);
        
        int ret = Solution().maxProfit(prices);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}