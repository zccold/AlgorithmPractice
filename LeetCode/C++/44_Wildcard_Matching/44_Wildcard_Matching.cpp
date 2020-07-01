#include <iostream>
#include <string>
#include <assert.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // bool isMatch(const string& s, const string& p, int i, int j){
    //     if(i == s.size()){
    //         while(j < p.size() && p[j] == '*')
    //             j++;
    //         return (j == p.size()) ? true : false;
    //     }
    //     if(j == p.size())
    //         return false;
    //     while(i < s.size() && j < p.size()){
    //         if(s[i] == p[j] || p[j] == '?'){
    //             i++, j++;
    //         }else{
    //             if(p[j] == '*'){
    //                 while(j+1 < p.size() && p[j+1] == '*')
    //                     j++;
    //                 return isMatch(s, p, i+1, j) || isMatch(s, p, i+1, j+1) || isMatch(s, p, i, j+1);
    //             }else{
    //                 return false;
    //             }
    //         }
    //     }
    //     if(i == s.size()){
    //         while(j < p.size() && p[j] == '*')
    //             j++;
    //         return (j == p.size()) ? true : false;
    //     }
    //     return false;
    // }
    
    // bool isMatch(string s, string p) {
    //     return isMatch(s, p, 0, 0);
    // }

    /* 
     * 匹配模式分为两类：一是s[i] == p[j]或p[j] == '?'，二是p[j] == '*'。
     * 当p[j] == '*'时，又可分为两类，a是匹配0个字符，b是匹配一个或多个字符。
     * 
     * 最直观的解法是回溯，但是回溯超时，这一是因为p可能存在"**"的模式使得回溯爆栈，
     * 二是isMatch(s, p, i+1, j) || isMatch(s, p, i+1, j+1) || isMatch(s, p, i, j+1)存在
     * 公共子结构。因此可用dp优化。
     * 
     * 若p[i] == '*'，则当它匹配0个字符时，dp[i+1][j+1] = dp[i][j+1]；
     *                  当它匹配1个或多个字符时，dp[i+1][j+1] = dp[i+1][j] || ... || dp[i+1][1]
     *                                                      = dp[i+1][j]
     */
    bool isMatch(string s, string p){
        vector<vector<bool>> dp(p.size()+1, vector<bool>(s.size()+1, false));
        dp[0][0] = true;
        for(int i = 0; i < p.size(); i++){
            if(p[i] == '*' && dp[i][0])
                dp[i+1][0] = true;
            else
                dp[i+1][0] = false;
        }
        for(int i = 0; i < p.size(); i++){
            for(int j = 0; j < s.size(); j++){
                if(s[j] == p[i] || p[i] == '?')
                    dp[i+1][j+1] = dp[i][j];
                else if(p[i] == '*')
                    dp[i+1][j+1] = dp[i][j+1] || dp[i+1][j];
                else
                    dp[i+1][j+1] = false;
            }
        }
        return dp.back().back();
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);
        
        bool ret = Solution().isMatch(s, p);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}