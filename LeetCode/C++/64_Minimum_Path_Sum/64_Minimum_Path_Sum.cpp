#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows, cols;
        rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> matrix(rows, vector<int>(cols, 0));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(i == 0 && j == 0){
                    matrix[i][j] = grid[i][j];
                }else{
                    int tmp = INT_MAX;
                    if(i-1 >= 0)
                        tmp = matrix[i-1][j]+grid[i][j];
                    if(j-1 >= 0)
                        tmp = min(tmp, matrix[i][j-1]+grid[i][j]);
                    matrix[i][j] = tmp;
                }
            }
        }
        return matrix[rows-1][cols-1];
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
    stringstream ss(line);
    string item;
    char delim = ',';
    while(getline(ss, item, delim))
        vi.push_back(stoi(item));
    return vi;
}

vector<vector<int>> stringToVectorVectorInt(string line){
    vector<vector<int>> vvi;
    trimLeftTrailingSpaces(line);
    trimRightTrailingSpaces(line);
    stringstream ss(line.substr(2, line.size()-4));
    string item;
    char delim = ']';
    while(getline(ss, item, delim)){
        vvi.push_back(stringToVectorInt(item));
        getline(ss, item, '[');
    }     
    return vvi;
}

int main(void){
    while(true){
        string line;
        getline(cin, line);
        vector<vector<int>> matrix = stringToVectorVectorInt(line);
        int res = Solution().minPathSum(matrix);
        cout<<to_string(res);
    }
}