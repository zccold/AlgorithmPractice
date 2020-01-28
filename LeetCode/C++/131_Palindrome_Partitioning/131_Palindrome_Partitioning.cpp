#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    bool isPalindrome(string& s, int l, int r){
        bool flag = true;
        while(l < r){
            if(s[l++] != s[r--]){
                flag = false;
                break;
            }
        }   
        return flag;
    }

    vector<vector<string>> dfs(string s){
        if(s.empty()) return vector<vector<string>>{vector<string>()};
        vector<vector<string>> res;
        for(int len = 1; len <= s.size(); len++){
            if(isPalindrome(s, 0, len-1)){
                string sub = s.substr(0, len);
                vector<vector<string>> childRes = dfs(s.substr(len, s.size()-len));
                for(auto& vs : childRes) vs.insert(vs.begin(), sub);
                res.insert(res.end(), childRes.begin(), childRes.end());
            }
        }
        return res;
    }

    vector<vector<string>> partition(string s) {
        return dfs(s);
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

string stringToString(string input){
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    return input.substr(1, input.size()-2);
}

string vectorVectorStringToString(vector<vector<string>>& palindromes){
    string str("[\n");
    for(auto vs : palindromes){
        str += "\t[";
        for(auto s : vs){
            str += "\"" + s + "\", ";
        }
        str = str.substr(0, str.size()-2);
        str += "],\n";
    }
    str = str.substr(0, str.size()-2);
    str += "\n]";
    return str;
}

int main(void){
    while(true){
        string line;
        getline(cin, line);
        string s = stringToString(line);
        vector<vector<string>> palindromes = Solution().partition(s);
        string str = vectorVectorStringToString(palindromes);
        cout<<str<<endl;
    }
}