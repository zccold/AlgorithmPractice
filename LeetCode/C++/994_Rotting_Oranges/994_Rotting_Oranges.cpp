#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    /*
     * BFS就行，不过其中一些处理比较技巧
     * 使用int来对新鲜橘子计数，而不是维持set集合。
     * 
     * 使用两个队列来“层次遍历”
     * 
     * 当前队列有腐烂橘子但是grid中已没有新鲜橘子时，代码中time不应该再递增。
     * 代码中通过bool isRotten来判断，最简单的是通过检查int fresh是否为0.
     */
    int orangesRotting(vector<vector<int>>& grid) {
        vector<queue<pair<int, int>>> rottens(2, queue<pair<int, int>>());
        int idx = 0;
        int fresh = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1)
                    fresh++;
                if(grid[i][j] == 2)
                    rottens[0].push(make_pair(i, j));
            }
        }

        int time = 0;
        vector<int> rows{0, -1, 0, 1}, cols{-1, 0, 1, 0};
        while(!rottens[idx].empty()){
            bool isRotten = false;
            while(!rottens[idx].empty()){
                pair<int, int> orange = rottens[idx].front();
                rottens[idx].pop();
                for(int i = 0; i < 4; i++){
                    int row = orange.first + rows[i];
                    int col = orange.second + cols[i];
                    if(row >= 0 && row < grid.size() 
                        && col >= 0 && col < grid[0].size() 
                        && grid[row][col] == 1)
                    {
                        rottens[1-idx].push(make_pair(row, col));
                        fresh--;
                        grid[row][col] = 2;
                        isRotten = true;
                    }
                }
            }
            if(isRotten) time++;
            idx = 1-idx;
        }
        return fresh == 0 ? time : -1;
    }
};

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                    return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                    return !isspace(ch);
                }).base(),
                input.end());
}

vector<vector<int>> stringToVVI(string input){
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    stringstream ss(input.substr(2, input.size()-4));
    string rows;
    char rowDelim = ']';
    vector<vector<int>> res;
    while(getline(ss, rows, rowDelim)){
        stringstream rowsSS(rows);
        string item;
        char colDelim = ',';
        vector<int> tmp;
        while(getline(rowsSS, item, colDelim)){
            tmp.push_back(stoi(item));
        }
        res.push_back(tmp);
        getline(ss, rows, '[');
    }
    return res;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<vector<int>> grid = stringToVVI(line);
        int time = Solution().orangesRotting(grid);
        cout << time << endl;
    }
    return 0;
}