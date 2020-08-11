#include <assert.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * 哪有什么简单题啊！！！
     * 这道题类似于进制转换，不过普通的进制转换例如10进制转2进制，2被映射为10，
     * 即每一位被映射到0-1区间，产生一个进位。
     * 但是在本题中，2应该被映射为2，即每一位被映射到1-2区间，没有进位。
     * 
     * 思路：使用取余运算，从低位到高位依次求每一位的映射值，
     * 第一次取余时将原值减1，余数，即求出的这一位的映射值再加上1.
     * 注意：所有求出的映射值都要加1，但是减1只在第一次取余时执行。
     */
    string convertToTitle(int n) {
        string res;
        div_t d;
        do {
            d = div(n - 1, 26);
            n = d.quot;
            res.insert(res.begin(), d.rem + 64 + 1);
        } while(d.quot > 26);

        if(d.quot)
            res.insert(res.begin(), d.quot + 64);
        return res;
    }
};

int main() {

    string line;
    while (getline(cin, line)) {
        int n = stoi(line);

        string out = Solution().convertToTitle(n);
        cout << out << endl;
    }
    return 0;
}