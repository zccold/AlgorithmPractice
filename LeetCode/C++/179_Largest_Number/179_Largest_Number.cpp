#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <sstream>
#include <memory>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    /*
     * 思路：连接数组元素组成最大值，即优先选择较大的位数放在高位，将数组元素转为string排序即可。
     *      问题是数组元素位数不一致，例如30和3。则可以自定义比较函数，"30"+"3" > "3" + "30" ? "303" : "330"
     *      边界case是数组元素全为0，则直接返回0.
     */
    string largestNumber(vector<int>& nums) {
        if(find_if(nums.begin(), nums.end(), [](const int& num) {
            return num != 0;
        }) == nums.end()) {
            return "0";
        }
        vector<string> strs;
        for(auto& num : nums) {
            strs.push_back(to_string(num));
        }

        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            string ab = a + b;
            string ba = b + a;
            return ab > ba ? 1 : 0;
        });
        string res;
        for(auto& str : strs) {
            res += str;
        }
        return res;
    }
};

vector<int> stringToVectorInt(string input) {
    vector<int> res;
    stringstream ss(input.substr(1, input.size() - 2));
    string item;
    char delim = ',';
    while(getline(ss, item, delim)) {
            res.push_back(stoi(item));
        }
    return res;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToVectorInt(line);
        
        string num = Solution().largestNumber(nums);

        cout << num << endl;
    }
    return 0;
}