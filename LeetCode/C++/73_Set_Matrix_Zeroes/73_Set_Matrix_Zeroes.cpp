#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int isFirstColZero(1);
        for(int i = 0; i < rows; i++){
            if(matrix[i][0] == 0)
                isFirstColZero = 0;
            for(int j = 1; j < cols; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            
        }
        if(matrix[0][0] == 0)
            for(int j = 1; j < cols; j++)
                matrix[0][j] = 0;
        if(isFirstColZero == 0)
            for(int i = 0; i < rows; i++)
                matrix[i][0] = 0;
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

string VectorVectorIntToString(vector<vector<int>>& vvi){
    string str("[");
    for(auto vi : vvi){
        str += "\n\t[";
        for(auto i : vi){
            str += to_string(i) + ",";
        }
        str.erase(str.end()-1);
        str += "],";
    }
    str.erase(str.end()-1);
    str += "\n]";
    return str;
}

int main(void){
    while(true){
        string line;
        getline(cin, line);
        vector<vector<int>> matrix = stringToVectorVectorInt(line);
        Solution().setZeroes(matrix);
        cout<<VectorVectorIntToString(matrix)<<endl;
    }
}