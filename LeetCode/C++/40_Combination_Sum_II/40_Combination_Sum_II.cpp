#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void recursive(vector<vector<int>>& res, vector<int> tmp, vector<int>& candidates, int target, int idx){
        int i = idx;
        while(i < candidates.size()){
            if(target > candidates[i]){
                tmp.push_back(candidates[i]);
                recursive(res, tmp, candidates, target-candidates[i], i+1);
                tmp.erase(tmp.end()-1);
            }else if(target == candidates[i]){
                tmp.push_back(candidates[i]);
                res.push_back(tmp);
            } 
            while(i+1 < candidates.size() && candidates[i] == candidates[i+1]) i++;
            i++;
        }       
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        recursive(res, vector<int>(), candidates, target, 0);
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
        vector<int> candidates = stringToVectorInt(line);
        getline(cin, line);
        int target = stoi(line);
        vector<vector<int>> ret = Solution().combinationSum2(candidates, target);
        cout<<VectorVectorIntToString(ret);
    }
}