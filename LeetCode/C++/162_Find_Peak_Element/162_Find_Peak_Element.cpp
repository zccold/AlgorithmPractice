#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l(0), r(nums.size()-1);
        while(l < r){
            int mid = (l+r)/2;
            int gt(INT_MIN);
            if(mid+1 < nums.size())
                gt = nums[mid+1];

            if(nums[mid] < gt){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return l;
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
        
        int ret = Solution().findPeakElement(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}