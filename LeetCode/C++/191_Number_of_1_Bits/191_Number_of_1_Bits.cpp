#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t mask = (1 << 8) - 1;
        int count = 0;
        for(int i = 0; i < 32; i += 8) {
            uint32_t byte = n & (mask << i);
            count += getByteHammingWeight(byte);
        }
        return count;
    }
private:
    int getByteHammingWeight(uint32_t byte) {
        if(cached.find(byte) != cached.end()) {
            return cached[byte];
        }
        int count = 0;
        uint32_t tmp = byte;
        while(tmp) {
            count += (tmp & 1);
            tmp >>= 1;
        }
        cached[byte] = count;
        return count;
    }
    map<uint32_t, int> cached;
};

int main() {
    string line;
    while (true) {
        getline(cin, line);
        
        uint32_t n = stoi(line);

        int count = Solution().hammingWeight(n);
        cout << count << endl;
    }
    return 0;
}