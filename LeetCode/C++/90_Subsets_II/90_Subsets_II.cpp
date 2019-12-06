#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    void recursive(vector<vector<int>>& res, vector<int>& sub, vector<int>& nums, int len, int idx){
        if(sub.size() == len){
            res.push_back(sub);
            return;
        }
        int i = idx;
        while(i < nums.size()){
            sub.push_back(nums[i]);
            recursive(res, sub, nums, len, i+1);
            sub.pop_back();
            while(++i < nums.size() && nums[i] == nums[i-1]);
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= nums.size(); i++)
            recursive(res, sub, nums, i, 0);
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

string VectorVectorIntToString(vector<vector<int>>& vvi){
    string str("[");
    for(auto vi : vvi){
        str += "\n\t[";
        for(auto i : vi){
            str += to_string(i) + ",";
        }
        str.erase(str.end()-1);
        str += "],";
    }
    str.erase(str.end()-1);
    str += "\n]";
    return str;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        vector<vector<int>> ret = Solution().subsetsWithDup(nums);

        string out = VectorVectorIntToString(ret);
        cout << out << endl;
    }
    return 0;
}