#include <iostream>
#include <string>
#include <assert.h>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dir;
        stringstream ss(path);
        string item;
        char delim('/');
        while(getline(ss, item, delim)){
            if(item == ".."){
                if(dir.size()) dir.pop_back();
            }else if(item.size() && item != "."){
                dir.push_back(item);
            }
        }
        string res;
        for(auto str : dir){
            res += "/" + str;
        }
        return res.size() ? res : string("/");
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
        string path = stringToString(line);
        
        string ret = Solution().simplifyPath(path);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}