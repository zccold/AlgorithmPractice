#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /// can't ac testcase: 1 214748364
    /// Status: Time Limit Exceeded

    /// "/" is not work, because of the fraction inaccurate,
    /// we should use "%"
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0 || denominator == 0)
            return string("0");
        string res;
        int sign = ((numerator >= 0) ^ (denominator >= 0)) ? -1 : 1;
        if(sign == -1)
            res += "-";

        // can't use abs(numerator) or abs(denominator), because of INT_MIN overflow.
        div_t d = div(numerator, denominator);
        // the sign of div() is complexed, just barrier it
        res += to_string(abs(d.quot));
        if(d.rem == 0)
            return res;
        
        res += ".";
        numerator = d.rem*10;
        unordered_map<int, pair<size_t, int>> idx;
        while(numerator != 0){
            div_t d = div(numerator, denominator);
            int unsigned_quot = abs(d.quot);
            res += to_string(unsigned_quot);

            auto it = idx.find(unsigned_quot);
            if(it != idx.end()){
                // can't ac testcase:4 333
                // if(it->second.second == d.rem){
                //     size_t rptStrLen = res.size() - it->second.first;
                //     size_t rptStrIdx = it->second.first - rptStrLen;
                //     string rptStr = res.substr(it->second.first, rptStrLen);
                //     res.replace(rptStrIdx, rptStrLen*2, "(" + rptStr + ")");
                //     return res;
                // }
                size_t rptStrLen = res.size() - it->second.first;
                // rptStrIdx may out of range, so type is int
                int rptStrIdx = it->second.first - rptStrLen;
                if(rptStrIdx >= 0){
                    string rpt1 = res.substr(it->second.first, rptStrLen);
                    string rpt2 = res.substr(rptStrIdx, rptStrLen);
                    if(rpt1 == rpt2 && it->second.second == d.rem){
                        res.replace(rptStrIdx, rptStrLen*2, "(" + rpt1 + ")");
                        return res;
                    }     
                }
            }
            idx[unsigned_quot] = make_pair(res.size(), d.rem);
            numerator = d.rem*10;
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
}