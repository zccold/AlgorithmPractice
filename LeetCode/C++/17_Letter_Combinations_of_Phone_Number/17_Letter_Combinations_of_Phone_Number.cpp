#include <iostream>
#include <sstream>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
    void recursive(string element, string& digits, int i, vector<string>& dts, vector<string>& res){
        if(i == digits.size()){
            res.push_back(element);
        }else{
            int idx = stoi(digits.substr(i, 1))-2;
            for(int j = 0; j < dts[idx].size(); j++){
                recursive(element + dts[idx].substr(j, 1), digits, i+1, dts, res);
            }
        }
    }

    vector<string> letterCombinations(string digits) {  
        vector<string> dts = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;

        recursive(string(), digits, 0, dts, res);

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
        string str = stringToString(line);
        
        vector<string> ret = Solution().letterCombinations(str);

        string out("[\"");
        for(auto t : ret){
            out += t;
            out += "\", \"";
        }
        out = out.substr(0, out.size()-3);
        out += "\"]";
        cout << out << endl;
    }
    return 0;
}