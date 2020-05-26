#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <assert.h>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1), ss2(version2);
        vector<int> vi1, vi2;
        string item;
        char delim('.');
        while(getline(ss1, item, delim)){
            vi1.push_back(stoi(item));
        }
        while(getline(ss2, item, delim)){
            vi2.push_back(stoi(item));
        }
        for(int i = 0; i < max(vi1.size(), vi2.size()); i++){
            int v1(0), v2(0);
            if(i < vi1.size())
                v1 = vi1[i];
            if(i < vi2.size())
                v2 = vi2[i];
            if(v1 < v2){
                return -1;
            }else if(v1 > v2){
                return 1;
            }
        }
        return 0;
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
        string version1 = stringToString(line);
        getline(cin, line);
        string version2 = stringToString(line);
        
        int ret = Solution().compareVersion(version1, version2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}