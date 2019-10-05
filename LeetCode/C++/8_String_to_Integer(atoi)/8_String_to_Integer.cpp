#include <iostream>
#include <string>
#include <assert.h>
#include <math.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int sign = 1, i;
        long res = 0;
        i = str.find_first_not_of(' ');
        if(i == str.npos)
            return 0;
        if(str[i] == '+' || str[i] == '-'){
            sign = str[i] == '-' ? -1 : 1;
            i++;
        }
        while(i < str.size()){
            if('0' <= str[i] && str[i] <= '9'){
                res = res*10 + (str[i] - '0');
                if(res > INT_MAX) return sign == 1 ? INT_MAX : INT_MIN;
            }else{
                break;
            }
            i++;
        }
        return res*sign;
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
        string str = stringToString(line);
        
        int ret = Solution().myAtoi(str);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}