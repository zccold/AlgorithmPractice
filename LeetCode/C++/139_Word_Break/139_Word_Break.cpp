#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for(int i = 0; i < s.size(); i++){
            for(auto word : wordDict){
                if(i+1 >= word.size() && true == dp[i-word.size()+1] 
                && s.substr(i-word.size()+1, word.size()) == word){
                    dp[i+1] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
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

string stringToString(string input){
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    return input;
}

vector<string> stringToVectorString(string input){
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    stringstream ss(input.substr(1, input.size()-2));
    string item;
    char delim(',');

    vector<string> res;
    while(getline(ss, item, delim)){
        res.push_back(item.substr(1, item.size()-2));
    }
    return res;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        getline(cin, line);
        vector<string> wordList = stringToVectorString(line);

        bool succeed = Solution().wordBreak(s, wordList);
        
    }
    return 0;
}