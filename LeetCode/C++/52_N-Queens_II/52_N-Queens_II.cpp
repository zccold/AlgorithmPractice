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
    int recursive(int n, int queen, vector<int> coord, vector<bool>& used) {
        if(queen == n) {
            return 1;
        }
        int total = 0;
        for(int i = 0; i < n; i++) {
            if(used[i] == false) {
                bool isSlash = false;
                for(int j = 0; j < coord.size(); j++) {
                    if( abs(queen - j) == abs(i - coord[j])) {
                        isSlash = true;
                        break;
                    }
                }
                if(!isSlash) {
                    coord.push_back(i);
                    used[i] = true;
                    total += recursive(n, queen + 1, coord, used);
                    used[i] = false;
                    coord.pop_back();
                }
            }
        }
        return total;
    }

    /*
     * 思路：需要确定每个皇后的行，列，使所有皇后都不在同一行、同一列、同一斜线上。
     *      回溯法：使用行递归，列迭代。即按顺序分别放置每一行的皇后，这样只需要确定每位皇后的列，
     *      使用mask避免两个皇后处于同一列，同一斜线则可通过两个皇后行差值、列差值相等判断。
     */
    int totalNQueens(int n) {
        vector<bool> used(n, false);
        return recursive(n, 0, vector<int>(), used);
    }
};

string vectorVectorStringToString(const vector<vector<string>>& vvs) {
    string res("[\n");
    for(auto vs : vvs) {
        res += "\t[\n";
        for(auto str : vs) {
            res += "\t\"";
            res += str;
            res += "\",\n";
        }
        res.erase(res.end() - 2, res.end());
        res += "\n\t],\n";
    }
    res.erase(res.end() - 2, res.end());
    res += "\n]";
    return res;
}

int main() {
    string line;
    while (true) {
        getline(cin, line);
        
        int n = stoi(line);

        vector<vector<string>> vvs = Solution().solveNQueens(n);

        string str = vectorVectorStringToString(vvs);

        cout << str << endl;
    }
    return 0;
}