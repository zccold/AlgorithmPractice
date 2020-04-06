#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <sstream>
#include <memory>
#include <algorithm>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        for(auto str : tokens){
            if(str == "+" || str == "-" || str == "*" || str == "/"){
                int operand2 = stack.back();
                stack.pop_back();
                int& operand1 = stack.back();
                switch(str[0]){
                case '+':
                    operand1 += operand2;
                    break;
                case '-':
                    operand1 -= operand2;
                    break;
                case '*':
                    operand1 *= operand2;
                    break;
                case '/':
                    operand1 /= operand2;
                }
            }else{
                stack.push_back(stoi(str));
            }
        }
        return stack.back();
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

vector<string> stringToVectorString(string input){
    vector<string> tokens;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    stringstream ss(input.substr(1, input.length() - 2));
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        tokens.push_back(item.substr(1, item.size()-2));
    }
    return tokens;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<string> tokens = stringToVectorString(line);
        
        int val = Solution().evalRPN(tokens);
        cout << val << endl;
    }
    return 0;
}