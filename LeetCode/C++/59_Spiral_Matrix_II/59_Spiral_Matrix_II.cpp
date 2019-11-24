#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int r, c, count;
        r = c = 0;
        count = 1;
        vector<int> dr{0, 1, 0, -1}, dc{1, 0, -1, 0};
        int didx = 0;
        while(r >= 0 && r < n && c >= 0 && c < n && matrix[r][c] == 0){
            matrix[r][c] = count++;
            int tmpr = r + dr[didx], tmpc = c + dc[didx];
            if(tmpr < 0 || tmpr >= n || tmpc < 0 || tmpc >= n || matrix[tmpr][tmpc]){
                didx = ++didx%4;
            }
            r += dr[didx], c += dc[didx];
        }
        return matrix;
    }
};

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
    str += "\n]\n";
    return str;
}

int main(void){
    while(true){
        string line;
        getline(cin, line);
        int n = stoi(line);
        vector<vector<int>> res = Solution().generateMatrix(n);
        cout<<VectorVectorIntToString(res);
    }
}