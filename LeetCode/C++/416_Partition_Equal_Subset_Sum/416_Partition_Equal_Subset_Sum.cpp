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
     * 平分数组使两个子数组和相等，可以转化为0-1背包问题：
     * 令背包大小为sum(nums)/2，求可以装进背包的数的最大和，判断最大和是否等于sum(nums)/2。
     */
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int half = sum / 2;
        if(half * 2 != sum)
            return false;
        vector<int> dp(half + 1, 0);
        for(auto num : nums){
            for(int i = half; i >= num; i--)
                dp[i] = max(dp[i], dp[i-num] + num);
        }
        return dp.back() == half;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        bool ret = Solution().canPartition(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}