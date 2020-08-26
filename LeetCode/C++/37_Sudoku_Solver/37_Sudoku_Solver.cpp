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
     * 思路：回溯法，关键是每个点可取的数受到三个约束，行、列、子矩阵。一种思路是每次迭代的时候
     *      遍历三个约束，另一种是缓存行、列、子矩阵约束，然后迭代时取每个点所处的位置约束的交集。
     *      从结果来看，后一种方法反而时间复杂度与空间复杂度较高。
     */
    bool recursive(vector<vector<char> >& board, 
                   vector<set<char> >& rows, 
                   vector<set<char> >& cols, 
                   vector<set<char> >& grids, 
                   vector<pair<int, int> >& nodes, int nodeIdx) {
        if(nodeIdx == nodes.size())
            return true;
        pair<int, int> node = nodes[nodeIdx];
        int gridIdx = node.first / 3 * 3 + node.second / 3;
        set<char> row(rows[node.first]), col(cols[node.second]), grid(grids[gridIdx]);
        set<char> tmp, allow;
        set_intersection(row.begin(), row.end(), col.begin(), col.end(), inserter(tmp, tmp.begin()));
        set_intersection(tmp.begin(), tmp.end(), grid.begin(), grid.end(), inserter(allow, allow.begin()));
        for(auto ch : allow) {
            rows[node.first].erase(ch);
            cols[node.second].erase(ch);
            grids[gridIdx].erase(ch);
            board[node.first][node.second] = ch;
            if(recursive(board, rows, cols, grids, nodes, nodeIdx + 1)) {
                return true;
            }
            rows[node.first].insert(ch);
            cols[node.second].insert(ch);
            grids[gridIdx].insert(ch);
        }
        return false;
    }

    void solveSudoku(vector<vector<char> >& board) {
        vector<char> nums = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        vector<set<char> > rows(9, set<char>(nums.begin(), nums.end()));
        vector<set<char> > cols(9, set<char>(nums.begin(), nums.end()));
        vector<set<char> > grids(9, set<char>(nums.begin(), nums.end()));
        vector<pair<int, int> > nodes;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    rows[i].erase(board[i][j]);
                    cols[j].erase(board[i][j]);
                    int gridIdx = i / 3 * 3 + j / 3;
                    grids[gridIdx].erase(board[i][j]);
                } else {
                    nodes.push_back(pair<int, int>(i, j));
                }
            }
        }
        recursive(board, rows, cols, grids, nodes, 0);
    }
};

vector<vector<char> > stringToVectorVectorChar(string input) {
    vector<vector<char> > res;
    stringstream ssGrid(input.substr(3, input.size() - 6));
    string row;
    char delimRow(']');
    char delimItem('"');
    while(getline(ssGrid, row, delimRow)) {
        vector<char> vc;
        stringstream ssRow(row);
        string item;
        while(getline(ssRow, item, delimItem)) {
            vc.push_back(item[0]);
            getline(ssRow, item, delimItem);
        }
        res.push_back(vc);
        getline(ssGrid, row, delimItem);
    }
    return res;
}

string vectorVectorCharToString(const vector<vector<char> >& board) {
    string res("[\n");
    for(auto row : board) {
        res += "\t[";
        for(auto ch : row) {
            res += "\"";
            res += ch;
            res += "\",";
        }
        res.erase(res.end() - 1);
        res += "],\n";
    }
    res.erase(res.end() - 2);
    res += "\n]";
    return res;
}

int main() {
    string line;
    while (true) {
        getline(cin, line);
        
        vector<vector<char> > board = stringToVectorVectorChar(line);

        Solution().solveSudoku(board);

        string str = vectorVectorCharToString(board);
        cout << str << endl;
    }
    return 0;
}