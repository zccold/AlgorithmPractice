#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * dp方法：dp[k, i] = max(dp[k, i-1], prices[i]-prices[j]+dp[k-1, j-1] (j = 1, ..., i))
     * 前i天的k次交易的总收益 = max{前i-1天的k次交易, 
     *                            第j天买入，第i天卖出收益 + 前j-1天k-1次收益}
     * 时间复杂度：O(kn)，当k远远大于n时，不如使用堆排序。
     */
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty() || k < 1)
            return 0;
        vector<vector<int>> dp(2, vector<int>(prices.size(), 0));
        int flip = 1, count = 1;
        do{
            int tmp = prices[0];
             for(int i = 1; i < prices.size(); i++){
                tmp = min(tmp, prices[i] - dp[1-flip][i-1]);
                dp[flip][i] = max(dp[flip][i-1], prices[i] - tmp);
            }
            count++;
            flip = 1 - flip;
        }while(count <= k && dp[flip].back() != dp[1-flip].back());
        return dp[1-flip].back();
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

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
        int k = stringToInteger(line);
        getline(cin, line);
        vector<int> prices = stringToIntegerVector(line);
        
        int ret = Solution().maxProfit(k, prices);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}