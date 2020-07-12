#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // 与41_First_Missing_Positive解决思路不同。
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet(nums.begin(), nums.end());
        int glblLong = 0;
        for(int i = 0; i < nums.size(); i++){
            if(hashSet.find(nums[i]-1) != hashSet.end())
                continue;
            int curLong = 1, curNum = nums[i];
            while(hashSet.find(curNum+1) != hashSet.end()){
                curLong++, curNum++;
            }
            glblLong = max(glblLong, curLong);
        }
        return glblLong;
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
        
        int ret = Solution().longestConsecutive(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}