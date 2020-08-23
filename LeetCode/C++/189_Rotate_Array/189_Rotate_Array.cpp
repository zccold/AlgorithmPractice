#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
     * 我的想法：使用两个下标i和j分别指向nums[0]和nums[nums.size()-k]，
     *          然后使用i遍历数组，交换i和j处值，这里对于j超过nums.size()如何处理的规律
     *          没有找到，可能有也可能没有。
     * 可行思路：题意为将整个数组向右循环移动k步，可以直接将每个值nums[i]移动到目的地
     *          nums[(i+k)%nums.size()]，但是移动前需要缓存目的地的原值。
     */
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        int count = 0;
        for(int start = 0; count < nums.size(); start++) {
            int current = start;
            int prev = nums[current];
            do {
                int next = (current + k) % nums.size();
                int tmp = nums[next];
                nums[next] = prev;
                prev = tmp;
                current = next;
                count++;
            } while(start != current);
        }
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

string vectorIntToString(vector<int>& vi) {
    string res("[");
    for(auto num : vi) {
        res += to_string(num) + ",";
    }
    res.erase(res.end()-1);
    res += "]";
    return res;
}

int main() {
    string line;
    while (true) {
        getline(cin, line);
        vector<int> array = stringToVectorInt(line);

        getline(cin, line);
        int k = stoi(line);

        Solution().rotate(array, k);
        cout << vectorIntToString(array) << endl;
    }
    return 0;
}