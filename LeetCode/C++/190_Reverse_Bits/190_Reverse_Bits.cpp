#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed = 0;
        int i = 0;
        while(n) {
            if((n & 1) == 1) {
                reversed += 1 << (31 - i);
            }
            n >>= 1;
            i++;
        }
        return reversed;
    }
};

int main() {
    string line;
    while (true) {
        getline(cin, line);
        
        uint32_t num = stoi(line, 0, 2);

        uint32_t reversed = Solution().reverseBits(num);
        cout << reversed << endl;
    }
    return 0;
}