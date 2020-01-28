#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    void bfs(vector<vector<char>>& board, queue<pair<int, int>>& q){
        vector<int> rowSteps{0, 0, 1, -1}, colSteps{1, -1, 0, 0};
        int i, j;
        pair<int, int> idx;
        while(!q.empty()){
            idx = q.front();
            i = idx.first, j = idx.second;
            q.pop();

            int iNew, jNew;
            for(int k = 0; k < rowSteps.size(); k++){
                iNew = i + rowSteps[k], jNew = j + colSteps[k];
                if(iNew >= 0 && iNew < board.size()
                        && jNew >= 0 && jNew < board[0].size()
                        && 'O' == board[iNew][jNew]){
                    q.push(pair<int, int>(iNew, jNew));
                    board[iNew][jNew]++;
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        
        vector<int> rowSteps{0, 1, 0, -1}, colSteps{1, 0, -1, 0};
        queue<pair<int, int>> q;
        int i = 0, j = 0, k = 0;
        while(k < 4){
            while(i >= 0 && i < board.size() && j >= 0 && j < board[0].size()){
                if('O' == board[i][j]){
                    q.push(pair<int, int>(i, j));
                    board[i][j]++;
                    bfs(board, q);
                }
                i += rowSteps[k], j += colSteps[k];
            }
            i -= rowSteps[k], j -= colSteps[k++];
        }

        for(i = 0; i < board.size(); i++){
            for(j = 0; j < board[0].size(); j++){
                if('O' == board[i][j]) board[i][j] = 'X';
                if('P' == board[i][j]) board[i][j]--;
            }
        }  
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

vector<vector<char>> stringToVectorVectorChar(string input){
    vector<vector<char>> board;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    stringstream ss(input.substr(2, input.size()-4));
    string rowString;
    char rowDelim(']');
    while(getline(ss, rowString, rowDelim)){
        stringstream rowSs(rowString);
        vector<char> rowChars;
        string item;
        char itemDelim(',');
        while(getline(rowSs, item, itemDelim)){
            rowChars.push_back(item[1]);
        }
        board.push_back(rowChars);
        getline(ss, rowString, '[');
    }
    return board;
}

int main(void){
    while(true){
        string line;
        getline(cin, line);
        vector<vector<char>> board = stringToVectorVectorChar(line);
        Solution().solve(board);
    }
}