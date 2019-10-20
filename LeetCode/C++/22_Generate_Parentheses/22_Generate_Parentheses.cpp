#include <iostream>
#include <string>
#include <assert.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    void recursive(int iLeft, int iRight, string element, vector<string>& res){
        if(iLeft == 0 && iRight == 0){
            element = "("+element+")";
            vector<char> stack;
            for(auto ch : element){
                if(ch == '('){
                    stack.push_back(ch);
                }else if(stack.size() > 0 && stack.back() == '('){
                    stack.pop_back();
                }else{
                    return;
                }
            }
            if(stack.size() == 0)
                res.push_back(element);
            return;
        }
        if(iLeft > 0)
            recursive(iLeft-1, iRight, element+"(", res);
        if(iRight > 0)
            recursive(iLeft, iRight-1, element+")", res);
        
    }

    vector<string> generateParenthesis(int n) {
        if(n <= 0)
            return vector<string>();
        vector<string> res;
        recursive(n-1, n-1, string(), res);
        return res;
    }
};

int stringToInt(string line){
    return stoi(line.substr(1, line.size()-2));
}

string vectorStringToString(vector<string> strs){
    string str("[\n\t\"");
    for(auto t : strs){
        str += t;
        str += "\",\n\t\"";
    }
    str = str.substr(0, str.size()-4);
    str += "\n]";
        
    return str;
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInt(line);
        
        vector<string> ret = Solution().generateParenthesis(n);

        string out = vectorStringToString(ret);
        cout << out << endl;
    }
    return 0;
}