#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    double recursive(double x, int n){
        if(n == 0){
            return 1;
        }else if(n == 1){
            return x;
        }else if(n == -1){
            return 1/x;
        }else{
            div_t d = div(n, 2);
            return d.rem == 0 ? recursive(x*x, d.quot)
                              : d.rem == 1 ? x*recursive(x*x, d.quot)
                              : 1/x*recursive(x*x, d.quot);
        }
    }
    double myPow(double x, int n) {
        if(x <= -100 || x >= 100 || x == 0) return 0.;
        return recursive(x, n);
    }
};

int main(void){
    while(true){
        string line;
        getline(cin, line);
        double x = stod(line);
        getline(cin, line);
        int n = stoi(line);
        double res = Solution().myPow(x, n);
        cout<<res<<endl;
    }
}