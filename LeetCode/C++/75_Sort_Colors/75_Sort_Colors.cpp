#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n0, n1, n2;
        n0 = n1 = n2 = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                nums[++n2] = 2, nums[++n1] = 1, nums[++n0] = 0;
            }else if(nums[i] == 1){
                nums[++n2] = 2, nums[++n1] = 1;
            }else{
                nums[++n2] = 2;
            }
        }
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
        
        Solution().sortColors(nums);

        string out = integerVectorToString(nums);
        cout << out << endl;
    }
    return 0;
}