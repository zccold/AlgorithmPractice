#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return vector<int>{-1, -1};
        vector<int> res;
        int l, r, tmp;
        l = 0, r = nums.size()-1;
        while(l < r){
            int mid = (l+r)/2;
            if(nums[mid] >= target){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        tmp = nums[l] == target ? l : -1;
        res.push_back(tmp);
        l = 0, r = nums.size()-1;
        while(l+1 < r){
            int mid = (l+r)/2;
            if(nums[mid] > target){
                r = mid-1;
            }else{
                l = mid;
            }
        }
        tmp = nums[r] == target ? r : nums[l] == target ? l : -1;
        res.push_back(tmp);
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        vector<int> ret = Solution().searchRange(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}