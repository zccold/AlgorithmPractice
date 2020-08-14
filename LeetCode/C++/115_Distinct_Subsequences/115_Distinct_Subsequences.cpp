#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<long long> dp(t.size()+1, 0);
        dp[0] = 1;
        
        for(auto chs : s){
            for(int i = t.size()-1; i >= 0; i--){
                if(chs == t[i])
                    dp[i+1] += dp[i];
            }
        }
        return dp.back();
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
    while (true) {
        getline(cin, line);
        trimLeft(line);
        trimRight(line);
        string s = line.substr(1, line.size()-2);

        getline(cin, line);
        trimLeft(line);
        trimRight(line);
        string t = line.substr(1, line.size()-2);

        int out = Solution().numDistinct(s, t);
        cout << out << endl;
    }
    return 0;
}