#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <sstream>
#include <memory>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    /*
     * 思路：要么假设勇士出发时需要一滴血，要么假设勇士救出公主后剩下一滴血。
     *      也即迭代路径从左上角到右下角或从右下角到左上角，区别是边界case的处理后一种思路更干净。
     */
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty()) {
            return 0;
        }
        int row = dungeon.size();
        int col = dungeon[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, INT_MAX));
        dp[row - 1][col] = 1;
        dp[row][col - 1] = 1;
        for(int i = row - 1; i >= 0; i--) {
            for(int j = col - 1; j >= 0; j--) {
                int need = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                // 这里need > 0而不是need >= 0是因为勇士出发时至少需要一滴血.
                dp[i][j] = need > 0 ? need : 1;
            }
        }
        return dp[0][0];
    }
};

vector<vector<int>> stringToVectorVectorInt(string input) {
    vector<vector<int>> res;
    stringstream ssGrid(input.substr(2, input.size() - 4));
    string row;
    char delimRow = ']', delimItem = ',';
    while(getline(ssGrid, row, delimRow)) {
        vector<int> vi;
        stringstream ssRow(row);
        string item;
        while(getline(ssRow, item, delimItem)) {
            vi.push_back(stoi(item));
        }
        res.push_back(vi);
        getline(ssGrid, row, '[');
    }
    return res;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<vector<int>> dungeon = stringToVectorVectorInt(line);
        
        int minHP = Solution().calculateMinimumHP(dungeon);

        cout << minHP << endl;
    }
    return 0;
}