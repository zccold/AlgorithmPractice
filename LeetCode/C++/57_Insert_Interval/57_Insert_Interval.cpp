#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
     * 思路：如果不使用newInterval初始化res，则编程处理它十分棘手。
     */
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res{newInterval};
        for(auto interval : intervals) {
            if(interval[0] > res.back()[1]) {
                res.push_back(interval);
            } else if(interval[1] < res.back()[0]) {
                vector<int> tmp = res.back();
                res.pop_back();
                res.push_back(interval);
                res.push_back(tmp);
            } else {
                res.back()[0] = min(res.back()[0], interval[0]);
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }
        return res;
    }
};

string vectorVectorStringToString(const vector<vector<string>>& vvs) {
    string res("[\n");
    for(auto vs : vvs) {
        res += "\t[\n";
        for(auto str : vs) {
            res += "\t\"";
            res += str;
            res += "\",\n";
        }
        res.erase(res.end() - 2, res.end());
        res += "\n\t],\n";
    }
    res.erase(res.end() - 2, res.end());
    res += "\n]";
    return res;
}

int main() {
    string line;
    while (true) {
        getline(cin, line);
        
        int n = stoi(line);

        vector<vector<string>> vvs = Solution().solveNQueens(n);

        string str = vectorVectorStringToString(vvs);

        cout << str << endl;
    }
    return 0;
}