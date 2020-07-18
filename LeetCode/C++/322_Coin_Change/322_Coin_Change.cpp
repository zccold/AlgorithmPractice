#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> res(amount+1, INT_MAX);
        res[0] = 0;
        for(int i = 1; i <= amount; i++){
            int tmp = INT_MAX;
            for(auto coin : coins)     
                if(coin <= i) tmp = min(tmp, res[i-coin]);
    
            res[i] = (tmp == INT_MAX) ? INT_MAX : tmp+1;
        }
        return (res.back() == INT_MAX) ? -1 : res.back();
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> coins = stringToIntegerVector(line);
        getline(cin, line);
        int amount = stringToInteger(line);
        
        int ret = Solution().coinChange(coins, amount);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}