#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int rows, cols, len;
        rows = matrix.size(), cols = matrix[0].size(), len = rows*cols;
        int l = 0, r = len-1;
        while(l < r){
            int mid = (l+r)/2;
            div_t d = div(mid, cols);
            if(matrix[d.quot][d.rem] == target){
                return true;
            }else if(matrix[d.quot][d.rem] > target){
                r = mid-1;
            }else{
                l = mid+1;
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
        getline(cin, line);
        int target = stoi(line);
        bool flag = Solution().searchMatrix(matrix, target);
        cout<<flag<<endl;
    }
}