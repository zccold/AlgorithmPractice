#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <sstream>
#include <memory>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n < 2) {
            return 0;
        }
        int count = 0;
        vector<bool> isPrimes(n, true);
        for(int i = 2; i < n; i++) {
            if(isPrimes[i]) {
                count++;
                for(int mul = 2; i * mul < n; mul++) {
                    isPrimes[i * mul] = false;
                }
            } 
        }
        return count;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stoi(line);
        
        int count = Solution().countPrimes(num);

        cout << count << endl;
    }
    return 0;
}