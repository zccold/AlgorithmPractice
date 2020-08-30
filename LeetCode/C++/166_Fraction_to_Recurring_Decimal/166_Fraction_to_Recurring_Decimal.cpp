#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    /*
     * 思路：这题最难的是处理各种边界case。
     *      case1：负数，而且是INT_MIN这种铁定溢出的负数，只能提升int为int64_t。
     *      case2：res的符号问题，由于提升int为int64_t，可直接将除数与被除数取正， 
     *             并直接计算res的符号。
     *      循环的处理比较简单，使用map记录每次计算后的余数与在res中的idx。
     */
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator == 0 || numerator == 0) {
            return string("0");
        }
        string res;
        res += ((numerator >= 0) ^ (denominator >= 0)) ? "-" : "";
        
        int64_t num, den;
        num = abs(static_cast<int64_t>(numerator));
        den = abs(static_cast<int64_t>(denominator));

        lldiv_t lld = div(num, den);
        res += to_string(lld.quot);
        if(lld.rem == 0) {
            return res;
        }
        res += ".";

        map<int64_t, int> numIdxs;
        int i = res.size();
        while(lld.rem) {
            num = lld.rem * 10;
            if(numIdxs.find(num) != numIdxs.end()) {
                int idx = numIdxs[num];
                res.insert(res.begin() + idx, '(');
                res += ")";
                return res;
            }
            numIdxs[num] = i++;
            lld = div(num, den);
            res += to_string(abs(lld.quot));
        }
        return res;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int numerator = stringToInteger(line);
        getline(cin, line);
        int denominator = stringToInteger(line);
        
        string ret = Solution().fractionToDecimal(numerator, denominator);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
    // int a = -5, b = -2;
    // div_t d = div(a, b);
    // cout << "-5%-2 = " << d.quot << ", " << d.rem << endl;
    // a = 5, b = -2;
    // d = div(a, b);
    // cout << "5%-2 = " << d.quot << ", " << d.rem << endl;
    // a = -5, b = 2;
    // d = div(a, b);
    // cout << "-5%2 = " << d.quot << ", " << d.rem << endl;
}