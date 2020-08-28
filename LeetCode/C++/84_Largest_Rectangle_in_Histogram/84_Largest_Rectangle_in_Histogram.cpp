#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    /*
     * 思路：先确定矩形的左右边，接着高度就确定了。时间复杂度为O(n^2)
     */
    int largestRectangleArea1(vector<int>& heights) {
        if(heights.empty()) {
            return 0;
        }
        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++) {
            int minHeight = heights[i];
            for(int j = i; j < heights.size(); j++) {
                minHeight = min(minHeight, heights[j]);
                maxArea = max(maxArea, minHeight * (j - i + 1));
            }
        }
        return maxArea;
    }

    /*
     * 思路：换一种思路，先确定矩形的高度，然后从左右两边去找高度不低于此的左右边。
     *      这样就可以通过缓存以空间换时间。
     */
    int largestRectangleArea(vector<int>& heights) {
        vector<int> leftLess(heights.size(), 0);
        vector<int> rightLess(heights.size(), 0);
        for(int i = 0; i < heights.size(); i++) {
            int j = i - 1;
            while(j >= 0 && heights[j] >= heights[i]) {
                j = leftLess[j];
            }
            leftLess[i] = j;
        }
        for(int i = heights.size() - 1; i >= 0; i--) {
            int j = i + 1;
            while(j < heights.size() && heights[j] >= heights[i]) {
                j = rightLess[j];
            }
            rightLess[i] = j;
        }

        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++) {
            maxArea = max(maxArea, heights[i] * (rightLess[i] - leftLess[i] - 1));
        }
        return maxArea;
    }
};

vector<int> stringToVectorInt(string input) {
    stringstream ss(input.substr(1, input.size() - 2));
    string item;
    char delim = ',';
    vector<int> res;
    while(getline(ss, item, delim)) {
        res.push_back(stoi(item));
    }
    return res;
}

int main() {
    string line;
    while (true) {
        getline(cin, line);

        vector<int> heights = stringToVectorInt(line);

        int area = Solution().largestRectangleArea(heights);

        cout << area << endl;
    }
    return 0;
}