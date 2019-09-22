#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>

using namespace std;

class Solution {
public:
    /*
     * 解法1：硬算
     */
    string convert(string s, int numRows) {
        if(numRows == 0 || numRows == 1)
            return s;
        int rows = numRows;
        int cols = s.size()/(numRows*2 - 2)*(numRows - 1);
        int rmnd = s.size()%(numRows*2 - 2);
        if(rmnd/numRows != 0){
            cols += (rmnd - numRows);
        }
        cols++;

        string res(rows*cols, ' ');

        int i = 0, row = 0, col = 0;
        while(i < s.size()){
            while(i < s.size() && row < rows)
                res[row++*cols + col] = s[i++];
            --row;
            while(i < s.size() && row > 0)
                res[--row*cols + ++col] = s[i++];
            ++row;
        }

        for(int i = res.size()-1; i > 0; i--){
            if(res[i] == ' ')
                res.erase(i, 1);
        }
        return res;
    }

    /*
     * 解法2：找规律
     */
    string convert2(string s, int numRows) {
        if(numRows == 1)
            return s;
        string res = "";
        int c = (numRows - 1)*2;
        for(int j = 0; j < numRows; j++)
            for(int i = 0; i < s.size(); i++)
                if(i%c == j || i%c == c - j)
                    res += s[i];
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int numRows = stringToInteger(line);
        
        string ret = Solution().convert(s, numRows);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}