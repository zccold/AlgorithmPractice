#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /*
     * 哪里有什么简单题啊！！！
     * 最直观的想法是先求阶乘，再求末尾有多少个0，但是这样会溢出，且时间复杂度为n。
     * 分析：10由2*5组成，因此只需要求n! = 1*2...*n有多少个2*5，
     *      又由于2总是比5多，所以只需要考虑5的个数。对n = 30，包含乘数5的数为{5,10,15,20,25,30}。
     *      其中既有一个5的数：5，还有两个5的数：25，也可能有三个5的数：125。
     * 思路：count = n/5 + n/25 + n/125 + ... 
     */
    int trailingZeroes(int n) {
        if(n <= 0) return 0;
        return n/5 + trailingZeroes(n/5);
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stoi(line);

        int out = Solution().trailingZeroes(n);
        cout << out << endl;
    }
    return 0;
}