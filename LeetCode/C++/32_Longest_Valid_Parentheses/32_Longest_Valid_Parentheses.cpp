#include <iostream>
#include <string>
#include <assert.h>
#include <vector>

using namespace std;

class Solution {
public:
    // template<class T> 
    // int traverse(T begin, T end){
    //     int left = 0, right = 0, maxLen = 0;
    //     for(auto ptr = begin; ptr != end; ptr++){
    //         if(*ptr == '('){
    //             left++;
    //         }else{
    //             right++;
    //             if(left == right) maxLen = max(maxLen, left+right);
    //             if(left < right) left = right = 0;
    //         }
    //     }
    //     return maxLen;
    // }
    // int longestValidParentheses(string s) {
    //     int res1 = traverse<string::iterator>(s.begin(), s.end());
    //     int res2 = traverse<string::reverse_iterator>(s.rbegin(), s.rend());
    //     return max(res1, res2);
    //     // return max(traverse<string::iterator>(s.begin(), s.end()), 
    //     //            traverse<string::reverse_iterator>(s.rbegin(), s.rend()));
    // }

    int longestValidParentheses(string s) {
        vector<int> stack{-1};
        int maxLen = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')
                stack.push_back(i);
            else{
                stack.pop_back();
                if(!stack.size()){
                    stack.push_back(i);
                }else{
                    maxLen = max(maxLen, i-stack.back());
                }
            }
        }
        return maxLen;
    }

    int longestValidParentheses1(string s) {
        vector<int> dp(s.size(), 0);
        for(int i = 1; i < s.size(); i++){
            if(s[i] == ')'){
                if(s[i-1] == '('){
                    dp[i] += 2;
                    if(i-2 >= 0)
                        dp[i] += dp[i-2];
                }
                else{
                    if(i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '('){
                        dp[i] += dp[i-1] + 2;
                        if(i-dp[i-1]-2 >= 0)
                            dp[i] += dp[i-dp[i-1]-2];
                    }
                }
            }
        }
        int res = 0;
        for(auto t : dp)
            if(t > res) res = t;
        return res;
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

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().longestValidParentheses(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}