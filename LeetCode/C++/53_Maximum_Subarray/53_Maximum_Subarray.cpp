#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    int recursive(vector<int>& nums, int l, int r){
        if(l == r)
            return nums[l];
        if(l > r)
            return INT_MIN;
        int mid = (l+r)/2;
        int leftMax = recursive(nums, l, mid-1);
        int rightMax = recursive(nums, mid+1, r);
        int lsum = 0, rsum = 0;
        for(int i = mid-1, sum = 0; i >= l; i--){
            sum += nums[i];
            lsum = max(lsum, sum);
        }
        for(int i = mid+1, sum = 0; i <= r; i++){
            sum += nums[i];
            rsum = max(rsum, sum);
        }
        int midMax = lsum + nums[mid] + rsum;
        return max(max(leftMax, rightMax), midMax);
    }

    int maxSubArray(vector<int>& nums){
        return recursive(nums, 0, nums.size()-1);
    }

    int maxSubArray1(vector<int>& nums) {
        int curMax = 0, allMax = nums[0];
        for(auto num : nums){
            if(curMax < 0){
                curMax = num;
            }else{
                curMax += num;
            }
            allMax = max(curMax, allMax);
        }
        return allMax;
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
        
        int ret = Solution().maxSubArray(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}