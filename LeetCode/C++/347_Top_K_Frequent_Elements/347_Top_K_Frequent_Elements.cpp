#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:
    // 最大堆整理函数：若存在子节点大于当前节点，交换并迭代
    void max_heapify(vector<int>& nums,  unordered_map<int, int>& counts, int i, int len){
        int son = i*2+1;
        while(son < len){
            if(son+1 < len && counts[nums[son+1]] > counts[nums[son]]){
                son++;    
            }
            if(counts[nums[son]] > counts[nums[i]]){
                swap(nums[son], nums[i]);
                i = son, son = son*2+1;
            }else{
                return;
            }
        }
    }
    
    void heapSort(vector<int>& nums, unordered_map<int, int>& counts){
        for(int i = (nums.size()-2)/2; i >= 0; i--)
            max_heapify(nums, counts, i, nums.size());
        for(int i = nums.size()-1; i > 0; i--){
            swap(nums[0], nums[i]);
            max_heapify(nums, counts, 0, i);
        }
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numToFrqnt;
        for(auto num : nums)
            numToFrqnt[num]++;
        
        vector<int> numsk;
        for(auto kv : numToFrqnt)
            numsk.push_back(kv.first);

        heapSort(numsk, numToFrqnt);
        return vector<int>(numsk.rbegin(), numsk.rbegin()+k);
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        vector<int> ret = Solution().topKFrequent(nums, k);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}