#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <assert.h>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int carry = 0;
        int i = num1.size()-1;
        int j = num2.size()-1;
        while(i >= 0 || j >= 0){
            int tmp = 0;
            if(i >= 0)
                tmp += num1[i] - '0';
            if(j >= 0)
                tmp += num2[j] - '0';
            div_t d = div(tmp + carry, 10);
            res.insert(res.begin(), d.rem + '0');
            carry = d.quot;
            i--, j--;
        }
        return carry == 1 ? "1" + res : res;
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
        string num1 = stringToString(line);
        getline(cin, line);
        string num2 = stringToString(line);
        
        string ret = Solution().addStrings(num1, num2);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}