#include <iostream>
#include <string>
#include <assert.h>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        for(int i = 1; i < 4; i++){
            for(int j = i+1; j < i+4; j++){
                for(int k = j+1; k < j+4; k++){
                    if(k < s.size() && s.size()-k <= 3
                       && (i == 1 || s[0] != '0')
                       && (j-i == 1 || s[i] != '0') 
                       && (k-j == 1 || s[j] != '0') 
                       && (s.size()-k == 1 || s[k] != '0')){
                        int ip1, ip2, ip3, ip4;
                        ip1 = stoi(s.substr(0, i));
                        ip2 = stoi(s.substr(i, j-i));
                        ip3 = stoi(s.substr(j, k-j));
                        ip4 = stoi(s.substr(k, s.size()-k));
                        if(ip1 <= 255 && ip2 <= 255 && ip3 <= 255 && ip4 <= 255){
                            res.push_back(to_string(ip1) + "."+
                                          to_string(ip2) + "."+
                                          to_string(ip3) + "."+
                                          to_string(ip4));
                        }
                    }
                }
            }
        }
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

string vectorStringToString(vector<string>& vs){
    string str("[");
    for(auto s : vs){
        str += "\"" + s + "\", ";
    }
    str = str.substr(0, str.size()-2);
    str += "]";
    return str;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        vector<string> ret = Solution().restoreIpAddresses(s);

        string out = vectorStringToString(ret);
        cout << out << endl;
    }
    return 0;
}