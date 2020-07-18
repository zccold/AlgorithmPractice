#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int fib(int N) {
        if(N < 2)
            return N;
        int a = 0, b = 1;
        for(int i = 2; i <= N; i++){
            a = a + b;
            swap(a, b);
        }
        return b;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int N = stringToInteger(line);
        
        int ret = Solution().fib(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}