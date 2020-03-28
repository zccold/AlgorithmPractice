#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
     * dp[i] = max(dp[j]), 0 <= j < i && Vj < Vi 
     * return max(dp)
     * O(n^2)
     */
    int lengthOfLIS1(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int> dp(nums.size(), 1);
        int maxLen = 1;
        for(int i = 1; i < nums.size(); i++){
            int curLen = 0;
            for(int j = i-1; j >= 0; j--){
                if(nums[i] > nums[j])
                    curLen = max(curLen, dp[j]);
            }
            dp[i] = curLen+1;
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }

    /*
     * O(nlogn)意味着内层循环使用二分查找，则nums值要有序，且对应的最大长度也要有序。
     * 通过将dp改为idx为len，val为nums值可达到目的，映射关系为val为长度为idx的最小结尾元素。
     */
    int lengthOfLIS(vector<int>& nums){
        if(nums.size() == 0)
            return 0;
        vector<int> dp(nums.size()+1, INT_MAX);
        dp[0] = INT_MIN, dp[1] = nums[0];
        int maxLen = 1;
        for(int i = 1; i < nums.size(); i++){
            int l(0), r(i);
            while(r-l > 1){
                int mid = (l+r) / 2;
                if(dp[mid] < nums[i])
                    l = mid;
                else
                    r = mid-1;
            }
            int len = (dp[r] < nums[i] ? r : l) + 1;
            dp[len] = min(dp[len], nums[i]);
            maxLen = max(maxLen, len); 
        }
        return maxLen;
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
        
        int ret = Solution().lengthOfLIS(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}