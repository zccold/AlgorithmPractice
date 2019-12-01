#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || (board[i][j]&128) || board[i][j] != word[idx])
            return false;
        bool flag = false;
        board[i][j] |= 128;
        if(idx == word.size()-1){
            return true;
        }else{
            flag = dfs(board, word, i-1, j, idx+1)
                || dfs(board, word, i, j-1, idx+1)
                || dfs(board, word, i+1, j, idx+1)
                || dfs(board, word, i, j+1, idx+1);
        }
        board[i][j] &= 127;
        return flag;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()*board[0].size() < word.size())
            return false;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(dfs(board, word, i ,j, 0)){
                    return true;
                }
            }
        }
        return false;
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
    stringstream ss(line);
    string item;
    char delim = ',';
    while(getline(ss, item, delim))
        vc.push_back(item[1]);
    return vc;
}

vector<vector<char>> stringToVectorVectorChar(string line){
    vector<vector<char>> vvc;
    trimLeftTrailingSpaces(line);
    trimRightTrailingSpaces(line);
    stringstream ss(line.substr(2, line.size()-4));
    string item;
    char delim = ']';
    while(getline(ss, item, delim)){
        vvc.push_back(stringToVectorChar(item));
        getline(ss, item, '[');
    }     
    return vvc;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<vector<char>> matrix = stringToVectorVectorChar(line);
        
        getline(cin, line);
        trimLeftTrailingSpaces(line);
        trimRightTrailingSpaces(line);
        string str = line.substr(1, line.size()-2);

        bool ret = Solution().exist(matrix, str);

        cout << ret << endl;
    }
    return 0;
}