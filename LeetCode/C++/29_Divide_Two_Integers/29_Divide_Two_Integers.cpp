#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == INT_MIN)
            return dividend == INT_MIN ? 1 : 0;
        bool flag = false;
        if(dividend == INT_MIN){
            flag |= true;
            dividend++;
        }
        bool sig1, sig2, sig;
        sig1 = dividend == abs(dividend);
        sig2 = divisor == abs(divisor);
        sig = (sig1+sig2) != 1;
        
        dividend = abs(dividend);
        divisor = abs(divisor);

        int count, res = 0, tmp = divisor;
        while(dividend >= tmp){
            count = 1;
            divisor = tmp;
            while(dividend >= divisor){
                dividend -= divisor;
                res += count;
                if(INT_MAX-divisor < divisor)
                    break;
                divisor += divisor;
                count += count;
            }
        }
        return sig 
            ? ((flag && dividend+1 >= tmp) ? (INT_MAX == res ? res : res+1) : res) 
            : ((flag && dividend+1 >= tmp) ? -res-1 : -res);
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int dividend = stringToInteger(line);
        getline(cin, line);
        int divisor = stringToInteger(line);
        
        int ret = Solution().divide(dividend, divisor);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}