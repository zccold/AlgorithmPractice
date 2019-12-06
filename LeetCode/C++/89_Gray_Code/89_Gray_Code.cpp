#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{0};
        for(int i = 0; i < n; i++){
            for(int j = res.size()-1; j >= 0; j--){
                res.push_back(res[j] | 1<<i);
            }
        }
        return res;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        vector<int> ret = Solution().grayCode(n);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}