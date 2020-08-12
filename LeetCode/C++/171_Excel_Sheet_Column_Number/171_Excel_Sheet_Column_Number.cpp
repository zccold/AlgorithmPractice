#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for(auto ch : s) {
            res *= 26;
            res += ch - 64;
        }
        return res;
    }
};

void trimLeft(string& input){
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](char ch){
        return isspace(ch);
    }));
}

void trimRight(string& input){
    input.erase(find_if(input.rbegin(), input.rend(), [](char ch){
        return isspace(ch);
    }).base(), input.end());
}

int main() {
    string line;
    while (getline(cin, line)) {
        trimLeft(line);
        trimRight(line);

        int out = Solution().titleToNumber(line);
        cout << out << endl;
    }
    return 0;
}