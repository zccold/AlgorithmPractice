#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void recursive(vector<vector<int>>& res, vector<int> permutation, int n, int k, int idx){
        if(permutation.size() == k){
            res.push_back(permutation);
            return;
        }
        for(int i = idx; i <= n; i++){
            permutation.push_back(i);
            recursive(res, permutation, n, k, i+1);
            permutation.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        recursive(res, vector<int>(), n, k, 1);
        return res;
    }
};

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

int main(void){
    while(true){
        string line;
        getline(cin, line);
        int n = stoi(line);
        getline(cin, line);
        int k = stoi(line);
        vector<vector<int>> ret = Solution().combine(n, k);
        cout<<VectorVectorIntToString(ret)<<endl;
    }
}