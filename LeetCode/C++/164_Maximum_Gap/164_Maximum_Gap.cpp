#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Bucket {
public:
    Bucket() {
        used = false;
        minNum = INT_MAX;
        maxNum = INT_MIN;
    }
    void add(int num) {
        if(!used)
            used = true;
        if(num > maxNum)
            maxNum = num;
        if(num < minNum)
            minNum = num;
    }
    bool used;
    int minNum;
    int maxNum;
};

class Solution {
public:
    /*
     * 思路：求无序数组的相邻数最大间隔，已知条件有数组最小数到最大数的间隔gap，数组长度len。
     *      若假设数据均匀分布，则平均间隔为gap/(len-1)。根据鸽笼原理，如果有相邻数间隔小于
     *      平均间隔，则一定有相邻数间隔大于平均间隔。
     *      使用大小小于等于平均间隔的桶分割数组，相邻桶最大间隔就是无序数组的相邻数最大间隔。
     */
    int maximumGap(vector<int>& nums) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        if(numsSet.empty() || numsSet.size() == 1) {
            return 0;
        }
        int maxNum = INT_MIN, minNum = INT_MAX;
        for(auto num : numsSet) {
            if(num > maxNum)
                maxNum = num;
            if(num < minNum)
                minNum = num;
        }
        int bucketSize = (maxNum - minNum) / (numsSet.size() - 1);
        int bucketNum = ((maxNum - minNum + 1) / bucketSize) + 1;
        vector<Bucket> buckets(bucketNum, Bucket());
        for(auto num : numsSet) {
            int bcktIdx = (num - minNum + 1) / bucketSize;
            buckets[bcktIdx].add(num);
        }
        Bucket* prev = nullptr;
        int maxGap = 0;
        for(auto& cur : buckets) {
            if(cur.used) {
                if(prev) {
                    maxGap = max(maxGap, cur.minNum - prev->maxNum);
                }
                prev = &cur;
            }
        }
        return maxGap;
    }
};

void trimLeft(string& input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](char ch){
        return isspace(ch);
    }));
}

void trimRight(string& input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](char ch){
        return isspace(ch);
    }).base(), input.end());
}

vector<int> stringToVectorInt(string input) {
    stringstream ss(input.substr(1, input.size()-2));
    string item;
    char delim(',');
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
        vector<int> nums = stringToVectorInt(line);

        int gap = Solution().maximumGap(nums);
        cout << gap << endl;
    }
    return 0;
}