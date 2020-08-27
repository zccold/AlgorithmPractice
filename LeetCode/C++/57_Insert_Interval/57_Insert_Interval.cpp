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

vector<vector<int>> stringToVectorVectorInt(string input) {
    vector<vector<int>> res;
    stringstream ssGrid(input.substr(2, input.size() - 4));
    string row;
    char delimRow = ']', delimItem = ',';
    while(getline(ssGrid, row, delimRow)) {
        vector<int> vi;
        stringstream ssRow(row);
        string item;
        while(getline(ssRow, item, delimItem)) {
            vi.push_back(stoi(item));
        }
        res.push_back(vi);
        getline(ssGrid, row, '[');
    }
    return res;
}

vector<int> stringToVectorInt(string input) {
    vector<int> vi;
    stringstream ss(input.substr(1, input.size() - 2));
    string item;
    char delim = ',';
    while(getline(ss, item, delim)) {
        vi.push_back(stoi(item));
    }
    return vi;
}

string vectorVectorIntToString(const vector<vector<int>>& vvi) {
    string res("[");
    for(auto vi : vvi) {
        res += "[";
        for(auto num : vi) {
            res += num;
            res += ",";
        }
        res.erase(res.end() - 1);
        res += "],";
    }
    res.erase(res.end() - 1);
    res += "]";
    return res;
}

int main() {
    string line;
    while (true) {
        getline(cin, line);
        vector<vector<int>> intervals = stringToVectorVectorInt(line);
        
        getline(cin, line);
        vector<int> newInterval = stringToVectorInt(line);
        vector<vector<int>> newIntervals = Solution().insert(intervals, newInterval);

        string str = vectorVectorIntToString(newIntervals);

        cout << str << endl;
    }
    return 0;
}