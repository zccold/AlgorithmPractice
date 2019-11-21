#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void recursive(vector<vector<int>>& prmts, vector<int>& nums, int begin){
        if(begin == nums.size()){
            prmts.push_back(nums);
        }else{
            for(int i = begin; i < nums.size(); i++){
                using std::swap;
                swap(nums[begin], nums[i]);
                recursive(prmts, nums, begin+1);
                swap(nums[begin], nums[i]);
            }
        }
    }
    void recursive(vector<vector<int>>& prmts, vector<int> prmt, vector<bool>& used, int count, vector<int>& nums){
        if(count == nums.size()){
            prmts.push_back(prmt);
        }else{
            for(int i = 0; i < nums.size(); i++){
                if(!used[i]){
                    used[i] = true;
                    prmt.push_back(nums[i]);
                    recursive(prmts, prmt, used, count+1, nums);
                    prmt.pop_back();
                    used[i] = false;
                }
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        // vector<bool> used(nums.size(), false);
        // recursive(res, vector<int>(), used, 0, nums);
        recursive(res, nums, 0);
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

vector<int> stringToVectorInt(string line){
    vector<int> vi;
    trimLeftTrailingSpaces(line);
    trimRightTrailingSpaces(line);
    stringstream ss(line.substr(1, line.size()-2));
    string item;
    char delim = ',';
    while(getline(ss, item, delim))
        vi.push_back(stoi(item));
    return vi;
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
    str += "\n]\n";
    return str;
}

int main(void){
    while(true){
        string line;
        getline(cin, line);
        vector<int> nums = stringToVectorInt(line);
        vector<vector<int>> ret = Solution().permute(nums);
        cout<<VectorVectorIntToString(ret);
    }
}