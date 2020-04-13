#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
     * dp(K, N) = 1 + min{1<=X<=N}(max(dp(K-1, X-1), dp(K, N-X)))
     * 从N层楼中选择楼层X，使得dp(K, N)最小。当鸡蛋从X层楼扔下去摔破了，则dp(K-1, X-1)；
     * 否则，dp(K, N-X)。在最坏的情况下，应该选择两种情况中的较大者。
     * 显然，随着N的增长，dp单调递增。即dp(K-1, X-1)随X单调递增；dp(K, N-X)随X单调递减。
     * 猜想：当二者值相交时，取X使得dp(K, N)最小。
     */
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K+1, vector<int>(N+1, 0));
        for(int j = 1; j <= N; j++)
            dp[1][j] = j;
        for(int i = 1; i <= K; i++)
            dp[i][1] = 1;
        for(int i = 2; i <= K; i++){
            for(int j = 2; j <= N; j++){
                int l(1), r(j);
                while(l+1 < r){
                    int mid = (l+r)/2;
                    int dp1 = dp[i-1][mid-1], dp2 = dp[i][j-mid];
                    if(dp1 > dp2){
                        r = mid;
                    }else if(dp1 < dp2){
                        l = mid;
                    }else{
                        l = r = mid;
                    }
                }
                dp[i][j] = 1 + min(max(dp[i-1][l-1], dp[i][j-l]), 
                                   max(dp[i-1][r-1], dp[i][j-r]));
            }
        }
        return dp[K][N];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int K = stringToInteger(line);
        getline(cin, line);
        int N = stringToInteger(line);
        
        int ret = Solution().superEggDrop(K, N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}