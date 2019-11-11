#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char, int>> matchSmall;
        for(int i = 0; i < board.size(); i++){
            unordered_map<char, int> matchRow;
            unordered_map<char, int> matchCol;
            if(i%3 == 0) 
                matchSmall = vector<unordered_map<char, int>>(3, unordered_map<char, int>());
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] != '.' && (++matchRow[board[i][j]] == 2 || ++matchSmall[j/3][board[i][j]] == 2)
                   || board[j][i] != '.' && ++matchCol[board[j][i]] == 2)
                    return false;
            }
        }
        return true;
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

vector<char> stringToVectorChar(string line){
    vector<char> vc;
    trimLeftTrailingSpaces(line);
    trimRightTrailingSpaces(line);
    stringstream ss(line.substr(1, line.size()-3));
    string item;
    char delim = ',';
    while(getline(ss, item, delim))
        vc.push_back(item[1]);
    return vc;
}

int main(void){
    while(true){
        string line;
        int count = 11;
        vector<vector<char>> board;
        while(count){
            getline(cin, line);
            if(count != 1 && count != 11){
                board.push_back(stringToVectorChar(line));
            }
            count--;
        }
        bool ret = Solution().isValidSudoku(board);
        cout<<ret;
    }
}