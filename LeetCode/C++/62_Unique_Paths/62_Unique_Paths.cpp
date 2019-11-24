#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
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
        return matrix[m-1][n-1];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        int ret = Solution().uniquePaths(m, n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}