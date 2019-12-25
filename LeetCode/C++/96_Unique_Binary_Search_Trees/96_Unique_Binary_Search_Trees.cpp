#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n < 1) return 0;
        vector<int> g(n+1, 0);
        g[0] = g[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i; j++){
                g[i] += g[j-1]*g[i-j];
            }  
        }
        return g[n];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().numTrees(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}