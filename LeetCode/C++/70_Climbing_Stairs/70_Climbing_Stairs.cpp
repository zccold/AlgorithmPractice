#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;
        vector<int> res{1, 1};
        int idx = 0;
        for(int i = 2; i <= n; i++){
            res[idx] += res[1-idx];
            idx = 1-idx;
        }
        return res[1-idx];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().climbStairs(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}