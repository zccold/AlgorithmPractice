#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int l, r, mid;
        l = 1, r = x/2;
        while(l < r){
            mid = (l+r)/2;
            if(mid*mid <= x){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        return l;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().mySqrt(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}