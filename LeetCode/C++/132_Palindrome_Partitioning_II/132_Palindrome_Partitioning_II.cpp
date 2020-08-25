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

class Solution {
public:
    bool isPalindrome(const string& s, int l, int r) {
        while(l < r) {
            if(s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }

    /*
     * 思路：求字符串的回文子串最小划分，即求字符串的最少不相交回文子串。
     *      dp[r] = min(dp[l-1] + 1)，且s[l:r+1]满足回文子串。
     */
    int minCut(string s) {
        vector<int> dp(s.size()+1, INT_MAX);
        dp[0] = 0;
        for(int r = 0; r < s.size(); r++) {
            for(int l = 0; l <= r; l++) {
                if(isPalindrome(s, l, r)) {
                    dp[r+1] = min(dp[r+1], dp[l]+1);
                } 
            }
        }
        return dp.back()-1;
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

int main() {
    string line;
    while (true) {
        getline(cin, line);
        string s = line.substr(1, line.size()-2);

        int cuts = Solution().minCut(s);
        cout << cuts << endl;
    }
    return 0;
}