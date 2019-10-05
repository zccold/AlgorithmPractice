#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

class Solution {
public:
    bool recursiveFunc(string& s, string& p, int idxs, int idxp){
        if(idxs == s.size() && idxp == p.size())
            return true;

        bool flag = idxs < s.size() && (p[idxp] == s[idxs] || p[idxp] == '.') ? true : false;

        if(idxp+1 < p.size() && p[idxp+1] == '*'){
            return recursiveFunc(s, p, idxs, idxp+2) || flag && recursiveFunc(s, p, idxs+1, idxp);
        }else{
            return flag && recursiveFunc(s, p, idxs+1, idxp+1);
        }
    }

    bool isMatch(string s, string p) {
        return recursiveFunc(s, p, 0, 0);
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);
        
        bool ret = Solution().isMatch(s, p);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}