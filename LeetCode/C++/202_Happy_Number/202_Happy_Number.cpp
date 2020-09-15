#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <sstream>
#include <memory>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
    /*
     * 思路：根据n = 2，可推出如果数字平方和不等于1，则一定会形成一个环。可用快慢指针检测环来退出。
     */
    bool isHappy(int n) {
        if(n <= 0) {
            return false;
        }
        int slow = n, fast = n;
        do {
            slow = calcDigitsPow(slow);
            fast = calcDigitsPow(fast);
            fast = calcDigitsPow(fast);
            if(fast == 1) {
                return true;
            }
        } while(slow != fast);
        return false;
    }
private:
    int calcDigitsPow(int n) {
        int tmp = 0;
        while(n) {
            tmp += pow((n % 10), 2);
            n /= 10;
        }
        return tmp;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stoi(line);
        
        bool isHappy = Solution().isHappy(n);

        cout << isHappy << endl;
    }
    return 0;
}