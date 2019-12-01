#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        int l, r;
        l = 0, r = nums.size()-1;
        while(l < r){
            while(l+1 <= r && nums[l+1] == nums[l])
                l++;
            while(r-1 >= l && nums[r-1] == nums[r])
                r--;
            if(l < r){
                int mid = (l+r)/2;
                if(nums[mid] == target){
                    return true;
                }else if(nums[mid] > target && (nums[l] < nums[r] || nums[mid] < nums[r] || nums[l] <= target)
                         || nums[mid] < target && nums[l] >= nums[r] && target > nums[r] && nums[r] > nums[mid]){
                    r = mid;
                }else{
                    l = mid+1;
                }
            }
        }
        return target == nums[l] ? true : false;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        bool ret = Solution().search(nums, target);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}