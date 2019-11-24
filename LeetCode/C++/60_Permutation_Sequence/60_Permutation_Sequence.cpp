#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        using std::swap;
        vector<int> factorial{0, 1, 2, 6, 24, 120, 720, 5040, 40320};    
        string res;
        for(int i = 1; i <= n; i++)
            res += i + '0';

        k--;
        for(int i = n-1, idx = 0; i >= 1; i--, idx++){
            if(k >= factorial[i]){
                div_t d = div(k, factorial[i]);
                swap(res[idx], res[idx+d.quot]);
                sort(res.begin()+idx+1, res.end());
                k = d.rem;
            }
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
        int n = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        string ret = Solution().getPermutation(n, k);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}