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
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3)
            return vector<vector<int>>();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int i, l, r, sum;
        i = 0;
        while(i < nums.size()-2){
            l = i + 1, r = nums.size()-1;
            while(l < r){
                sum = nums[i]+nums[l]+nums[r];
                if(sum > 0){
                    r--;
                }else if(sum < 0){
                    l++;
                }else{
                    res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    while(l < r && nums[l+1] == nums[l])
                        l++;
                    while(l < r && nums[r-1] == nums[r])
                        r--;
                    l++, r--;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        vector<vector<int>> ret = Solution().threeSum(nums);

        string str("[");
        for(auto t : ret){
            str += "[";
            for(auto tt : t){
                str += to_string(tt);
                str += ", ";
            }
            str = str.substr(0, str.size()-2);
            str += "], ";
        }
        str = str.substr(0, str.size()-2);
        str += "]";
        cout << str << endl;
    }
    return 0;
}