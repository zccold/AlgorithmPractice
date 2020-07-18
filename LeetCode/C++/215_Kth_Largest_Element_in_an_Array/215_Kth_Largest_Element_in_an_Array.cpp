#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int partition(vector<int>& nums, int l, int r){
        // 不需要考虑l > r的情况，因为k保证有效
        // if(l > r)
        //     return -1;
        int pivot = nums[r];
        int i = l-1;
        for(int j = l; j < r; j++){
            if(nums[j] >= pivot)
                swap(nums[++i], nums[j]);
        }
        swap(nums[++i], nums[r]);
        return i;
    }

    int findKthLargestQuicksort(vector<int>& nums, int k, int l, int r){
        int idx = partition(nums, l, r);
        // 不需要考虑idx = -1的情况，因为k保证有效
        // if(idx == -1)
        //     return -1;
        if(idx+1 == k){
            return nums[idx];
        }else if(idx+1 > k){
            return findKthLargestQuicksort(nums, k, l, idx-1);
        }else{
            return findKthLargestQuicksort(nums, k, idx+1, r);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargestQuicksort(nums, k, 0, nums.size()-1);
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
        int k = stringToInteger(line);
        
        int ret = Solution().findKthLargest(nums, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}