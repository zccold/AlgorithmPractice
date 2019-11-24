#include <iostream>
#include <string>
#include <assert.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = 0;
        div_t d;
        int ia = a.size()-1, ib = b.size()-1;
        while(ia >= 0 && ib >= 0){
            d = div((a[ia--]-'0') + (b[ib--]-'0') + carry, 2);
            res += d.rem + '0';
            carry = d.quot;
        }
        while(ia >= 0){
            d = div((a[ia--]-'0') + carry, 2);
            res += d.rem + '0';
            carry = d.quot;
        }
        while(ib >= 0){
            d = div((b[ib--]-'0') + carry, 2);
            res += d.rem + '0';
            carry = d.quot;
        }
        if(carry) res += carry+'0';
        reverse(res.begin(), res.end());
        return res;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string a = stringToString(line);
        getline(cin, line);
        string b = stringToString(line);
        
        string ret = Solution().addBinary(a, b);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}