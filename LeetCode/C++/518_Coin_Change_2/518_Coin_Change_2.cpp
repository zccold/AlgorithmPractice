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
     * 首先思路为回溯：总价值从amount递归到0，每次从coins中选择不同的coin。
     * 接着考虑优化：
     * 第一种思路是改递归为自底向上迭代：总价值从0到amount迭代，每次从coins中选择不同的coin；
     * 存在的问题是重复计数：res[3] = 1(coin)->res[2] + 2(coin)->res[1]，
     * 这里1(coin)->2(coin)与2(coin)->1(coin)重复。
     * 
     * 第二种思路是dp：dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]]
     * i为前i种硬币，j为总价值，空间复杂度可优化。
     * 
     * 两种思路代码相似，但是按照第二种思路来看，一个是按列迭代计算，一个是按行迭代计算。
     */
    int change(int amount, vector<int>& coins) {
        vector<int> res(amount+1, 0);
        res[0] = 1;
        // 第一种思路
        // for(int i = 1; i <= amount; i++){
        //     for(auto coin : coins){
        //         if(i-coin >= 0)
        //             res[i] += res[i-coin];
        //     }
        // }
        // 第二种思路
        for(int coin : coins){
            for(int i = coin; i <= amount; i++){
                res[i] += res[i-coin];
            }
        }
        return res.back();
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
        int amount = stringToInteger(line);
        getline(cin, line);
        vector<int> coins = stringToIntegerVector(line);
        
        int ret = Solution().change(amount, coins);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}