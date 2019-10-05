#include <iostream>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x > INT_MAX || x <= INT_MIN)    
            return 0;
        int sign = abs(x) == x ? 1 : -1;
        string tmp = to_string(abs(x));
        std::reverse(tmp.begin(), tmp.end());
        long long res = stoll(tmp)*sign;
        return res <= INT_MAX && res >= INT_MIN ? res : 0;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}