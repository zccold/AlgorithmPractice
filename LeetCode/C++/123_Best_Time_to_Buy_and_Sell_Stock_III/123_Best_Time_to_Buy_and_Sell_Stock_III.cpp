#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * dp[k, i] = max(dp[k, i-1], prices[i]-prices[j]+dp[k-1, j-1] (j = 1, ..., i))
     */
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        vector<vector<int>> dp(3, vector<int>(prices.size(), 0));
        for(int k = 1; k < 3; k++){
            int tmp = prices[0];
            for(int i = 1; i < prices.size(); i++){
                tmp = min(tmp, prices[i] - dp[k-1][i-1]);
                dp[k][i] = max(dp[k][i-1], prices[i]-tmp);
            }
        }
        return dp.back().back();
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