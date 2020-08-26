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
    /*
     * 暴力1: 总留存雨水量 = 每个点留存雨水量之和，
     *      每个点留存雨水量 = 这个点左右最大高度能留存雨水 - 这个点高度
     */
    int trap1(vector<int>& height) {
        if(height.empty())
            return 0;
        int sum = 0;
        for(int i = 1; i < height.size() - 1; i++) {
            int left = height.front(), right = height.back();
            for(int j = 0; j < i; j++) {
                if(height[j] > left) {
                    left = height[j];
                }
            }
            for(int j = i + 1; j < height.size(); j++) {
                if(height[j] > right) {
                    right = height[j];
                }
            }
            int tmp = min(left, right) - height[i];
            if(tmp > 0) {
                sum += tmp;
            }
        }
        return sum;
    }
    /*
     * 思路2：显然，暴力存在重复子问题，可以缓存每个点的左右最大高度
     */
    int trap2(vector<int>& height) {
        if(height.empty())
            return 0;
        vector<int> lefts(height.size(), height.front());
        vector<int> rights(height.size(), height.back());
        int sum = 0;
        for(int i = 1; i < height.size(); i++) {
            lefts[i] = max(lefts[i-1], height[i]);
        }
        for(int j = height.size() - 2; j >= 0; j--) {
            rights[j] = max(rights[j+1], height[j]);
        }
        for(int i = 1; i < height.size() - 1; i++) {
            int tmp = min(lefts[i-1], rights[i+1]) - height[i];
            if(tmp > 0) {
                sum += tmp;
            }
        }
        return sum;
    }

    /*
     * 思路3：使用栈一次遍历
     */
    int trap(vector<int>& height) {
        vector<int> stack;
        int right = 0;
        int sum = 0;
        while(right < height.size()) {
            while(!stack.empty() && height[right] > height[stack.back()]) {
                int cur = stack.back();
                stack.pop_back();
                if(stack.empty()) {
                    break;
                }
                int left = stack.back();
                int dis = right - left - 1;
                int h = min(height[left], height[right]) - height[cur];
                sum += dis * h;
            }
            stack.push_back(right++);
        }
        return sum;
    }
};

vector<int> stringToVectorInt(string input) {
    vector<int> res;
    stringstream ss(input.substr(1, input.size() - 2));
    string item;
    char delim(',');
    while(getline(ss, item, delim)) {
        res.push_back(stoi(item));
    }
    return res;
}

int main() {
    string line;
    while (true) {
        getline(cin, line);
        
        vector<int> height = stringToVectorInt(line);

        int sum = Solution().trap(height);

        cout << sum << endl;
    }
    return 0;
}