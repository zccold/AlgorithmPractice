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
     * 思路：直观思路，bfs。
     *      优化1：bfs的迭代树明显存在重复子问题，例如[2,2,1,1,4]，idx=2遍历了两次，
     *      第一次是从idx0到idx2，第二次是从idx1到idx2，因此可用缓存法。提交结果超时。
     *      优化2：注意到，对[2,2,1,1,4]，因为idx=0能直接到idx=2，因此也必然可以到idx=1，
     *      在遍历时，维持当前最远可到达终点，并在此范围内求下一步最远可到达终点，这样只需要遍历一次。
     */
    int jump(vector<int>& nums) {
        int curEnd = 0;
        int nextEnd = 0;
        int jump = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i <= curEnd) {
                nextEnd = max(nextEnd, i + nums[i]);
            } else {
                jump++;
                curEnd = nextEnd;
                nextEnd = i + nums[i];
            }
        }
        return jump;
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
        
        vector<int> nums = stringToVectorInt(line);

        int jump = Solution().jump(nums);

        cout << jump << endl;
    }
    return 0;
}