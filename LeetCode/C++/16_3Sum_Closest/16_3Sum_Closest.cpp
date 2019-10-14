#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>
#include <sstream>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int res = nums[0]+nums[1]+nums[2];
        int i, l, r, sum;
        i = 0;
        while(i < nums.size()-2){
            l = i + 1, r = nums.size()-1;
            while(l < r){
                sum = nums[i]+nums[l]+nums[r];
                if(abs(sum - target) < abs(res - target))
                    res = sum;
                if(sum > target){
                    r--;
                }else if(sum < target){
                    l++;
                }else{
                    return target;
                }  
            }
            while(i < nums.size()-3 && nums[i+1] == nums[i])
                i++;
            i++;
        }
        return res;
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
        int target = stringToInteger(line);
        
        int ret = Solution().threeSumClosest(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}