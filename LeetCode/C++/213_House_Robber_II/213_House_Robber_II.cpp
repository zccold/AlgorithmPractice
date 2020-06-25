#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int robWithNoCircle(vector<int>& nums, int l, int r) {
        if(nums.empty())
            return 0;
        vector<int> dp(2, 0);
        int i = 0;
        for(int j = l; j <= r; j++){
            dp[i] = max(dp[1-i], dp[i]+nums[j]);
            i = 1-i;
        }
        return max(dp[0], dp[1]);
    }

    int rob(vector<int>& nums){
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];
        return max(robWithNoCircle(nums, 0, nums.size()-2), 
                   robWithNoCircle(nums, 1, nums.size()-1));
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
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().rob(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}