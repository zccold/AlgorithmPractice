#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows, cols;
        rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        vector<vector<unsigned>> matrix(rows, vector<unsigned>(cols, 0));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(obstacleGrid[i][j] != 1){
                    if(i == 0 && j == 0){
                        matrix[i][j] = 1;
                    }else{
                        if(i-1 >= 0)
                            matrix[i][j] += matrix[i-1][j];
                        if(j-1 >= 0)
                            matrix[i][j] += matrix[i][j-1];
                    }
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
        int res = Solution().uniquePathsWithObstacles(matrix);
        cout<<to_string(res);
    }
}