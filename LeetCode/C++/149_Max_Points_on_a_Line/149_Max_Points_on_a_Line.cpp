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
     * 思路：注意题意是求在同一条直线上的点，而不是斜率相同的点。
     *      后者包含前者，且会导致思路完全不同。
     *      如果是求在同一条直线上的点，则需要遍历点集中的每一个点，分别作为起点，再判断
     *      其他点是否在同一条直线上，此时可以通过斜率判断，因为起点相同。
     */
    int maxPoints(vector<vector<int>>& points) {
        if(points.empty())
            return 0;
        if(points.size() == 1)
            return 1;
        int maxCount = 2;
        for(int i = 0; i < points.size() - 1; i++) {
            map<pair<int, int>, int> lines;
            int duplicate = 0;
            for(int j = i + 1; j < points.size(); j++) {
                // 处理重复点
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    duplicate++;
                } else {
                    int x = points[i][0] - points[j][0];
                    int y = points[i][1] - points[j][1];
                    // 处理delta分别为(-1, 1)与(1, -1)这种情况
                    if(x < 0) {
                        x = -x, y = -y;
                    }
                    if(x == 0) {
                        lines[pair<int, int>(points[i][0], 0)]++;
                    } else if(y == 0) {
                        lines[pair<int, int>(0, points[i][1])]++;
                    } else {
                        lines[getKey(x, y)]++;
                    }
                }
            }
            for(auto line : lines) {
                maxCount = max(maxCount, line.second + 1 + duplicate);
            }
            maxCount = max(maxCount, 1 + duplicate);
        }
        return maxCount;
    }
private:
    pair<int, int> getKey(int x, int y) {
        int a = abs(x), b = abs(y);
        while(true) {
            if(a < b) {
                swap(a, b);
            }
            div_t c = div(a, b);
            if(c.rem == 0) {
                return pair<int, int>(x / b, y / b);
            }
            a = b, b = c.rem;
        }
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
        vector<vector<int>> points = stringToVectorVectorInt(line);
        
        int maxCount = Solution().maxPoints(points);

        cout << maxCount << endl;
    }
    return 0;
}