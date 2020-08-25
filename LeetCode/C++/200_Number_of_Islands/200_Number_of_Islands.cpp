#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        queue<pair<int, int>> q;
        vector<vector<int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    count++;
                    q.push(pair<int, int>(i, j));
                    grid[i][j] = '0';
                    while(!q.empty()) {
                        pair<int, int> tmp = q.front();
                        q.pop();
                        for(auto step : directions) {
                            int r = tmp.first + step[0];
                            int c = tmp.second + step[1];
                            if(r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == '1') {
                                q.push(pair<int, int>(r, c));
                                grid[r][c] = '0';
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};

vector<vector<char>> stringToVectorVectorChar(string input) {
    vector<vector<char>> res;
    stringstream ssMatrix(input.substr(3, input.size()-6));
    string row;
    char delimRow(']');
    while(getline(ssMatrix, row, delimRow)) {
        stringstream ssRow(row);
        string item;
        char delimItem('"');
        vector<char> vc;
        while(getline(ssRow, item, delimItem)) {
            vc.push_back(item[0]);
            getline(ssRow, item, delimItem);
        }
        res.push_back(vc);
    }
    return res;
}

int main() {
    string line;
    while (true) {
        getline(cin, line);
        
        vector<vector<char>> grid = stringToVectorVectorChar(line);

        int count = Solution().numIslands(grid);
        cout << count << endl;
    }
    return 0;
}