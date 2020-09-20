#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int diff = n - m;
        int res = 0;
        int i = 30;
        while(i >= 0 && (diff & static_cast<int>(pow(2, i))) == 0) {
            res += m & n & static_cast<int>(pow(2, i));
            i--;
        }
        return res;
    }
};

int main() {
    string line;
    while (true) {
        getline(cin, line);
        int m = stoi(line);
        getline(cin, line);
        int n = stoi(line);
        
        int mAndN = Solution().rangeBitwiseAnd(m, n);

        cout << mAndN << endl;
    }
    return 0;
}