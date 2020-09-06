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
     * 思路1：先确定矩形的高度，然后从左右两边去找高度不低于此的左右边。这样就可以通过缓存以空间换时间。
     */
    int largestRectangleArea1(vector<int>& heights) {
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

    /*
     * 思路2：使用单调递增栈，每个元素入栈一次，出栈一次，时间复杂度为O(n)。
     *        入栈时机为遍历到自己的时刻，出栈时机则是遍历到右边第一个高度低于自己的元素，
     *          而此时栈顶元素即为左边第一个高度低于自己的元素的下标。
     */
    int largestRectangleArea(vector<int>& heights) {
        // 为了弹出单调栈中所有元素
        heights.push_back(0);
        vector<int> stack;
        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++) {
            while(!stack.empty() && heights[stack.back()] > heights[i]) {
                int h = heights[stack.back()];
                stack.pop_back();
                int leftLess = stack.empty() ? -1 : stack.back();
                maxArea = max(maxArea, h * (i - leftLess - 1));
            }
            stack.push_back(i);
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