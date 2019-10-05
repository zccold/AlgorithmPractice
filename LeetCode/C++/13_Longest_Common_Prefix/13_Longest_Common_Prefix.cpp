#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return string("");
        string res;
        int len = INT_MAX;
        
        for(int i = 0; i < strs.size(); i++){
            if(strs[i].size() < len)
                len = strs[i].size();
        }
        
        for(int i = 0; i < len; i++){
            char ch = strs[0][i];
            for(int j = 1; j < strs.size(); j++){
                if(strs[j][i] != ch)
                    return res;
            }   
            res += string(1, ch);
        }     
        return res;
    }
};

void trimLeftTrailingSpaces(string& input){
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch){
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string& input){
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch){
        return !isspace(ch);
    }).base(), input.end());
}

vector<string> stringToStringVector(string input)
{
    vector<string> output;

    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length()-2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while(getline(ss, item, delim)){
        trimLeftTrailingSpaces(item);
        trimRightTrailingSpaces(item);
        item = item.substr(1, item.length()-2);
        output.push_back(item);
    }
    return output;
}

int main(void){
    string line;
    while(getline(cin, line)){
        vector<string> strs = stringToStringVector(line);

        string ret = Solution().longestCommonPrefix(strs);

        cout<<ret<<endl;
    }
    return 0;
}