#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        for(auto num : nums) {
            counts[num]++;
        }
        int maxNum = nums[0], maxCount = 1;
        for(auto it = counts.begin(); it != counts.end(); it++) {
            if(maxCount < it->second) {
                maxCount = it->second;
                maxNum = it->first;
            }
        }
        return maxNum;
    }
};

void trimLeft(string& input){
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](char ch){
        return isspace(ch);
    }));
}

void trimRight(string& input){
    input.erase(find_if(input.rbegin(), input.rend(), [](char ch){
        return isspace(ch);
    }).base(), input.end());
}

vector<int> stringToVectorInt(string str){
    trimLeft(str);
    trimRight(str);
    stringstream ss(str.substr(1, str.size()-2));
    string item;
    char delim(',');
    vector<int> res;
    while(getline(ss, item, delim)){
        res.push_back(stoi(item));
    }
    return res;
}

int main() {

    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToVectorInt(line);

        int out = Solution().majorityElement(nums);
        cout << out << endl;
    }
    return 0;
}