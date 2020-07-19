#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    /*
     * 二维0-1背包问题
     * 有一个需要注意的地方是j和k必须从0开始迭代，而不能是1或者count0、count1。
     * 因为是二维背包，当前str可能存在count0 == 0或者count1 == 0的情况。
     * 
     * 如果优化dp空间，则j和k可以从count0、count1开始，因为当前str的dp复用了上一个str的dp。
     * j和k小于count0、count1的情况被保留了下来。
     */
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        for(int i = 0; i < strs.size(); i++){
            int count0 = 0, count1 = 0;
            for(auto ch : strs[i]){
                if(ch == '0')
                    count0++;
                else
                    count1++;
            }
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= n; k++){
                    int tmp;
                    if(j-count0 >= 0 && k-count1 >= 0)
                        tmp = max(dp[i][j][k], dp[i][j-count0][k-count1]+1);
                    else
                        tmp = dp[i][j][k];
                    dp[i+1][j][k] = tmp;
                }
            }
        }
        return dp.back().back().back();
    }
};

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                    return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                    return !isspace(ch);
                }).base(),
                input.end());
}

vector<string> stringToVectorString(string input){
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    stringstream ss(input.substr(2, input.size()-4));
    string item;
    char delim = '"';
    vector<string> res;
    while(getline(ss, item, delim)){
        res.push_back(item);
        getline(ss, item, delim);
    }
    return res;
}

int main(){
    string line;
    while(true){
        getline(cin, line);
        vector<string> strs = stringToVectorString(line);
        getline(cin, line);
        int m = stoi(line);
        getline(cin, line);
        int n = stoi(line);
        int count = Solution().findMaxForm(strs, m, n);
        cout << count << endl;
    }
}