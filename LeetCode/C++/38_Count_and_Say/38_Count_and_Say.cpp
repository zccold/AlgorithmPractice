#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n < 1 || n > 30) return string();
        vector<shared_ptr<string>> str{shared_ptr<string>(new string("1")), 
                                       shared_ptr<string>(new string(""))};
        int idx = 0;
        for(int i = 2; i <= n; i++){
            int num = (*str[idx])[0], count = 1;
            for(int j = 1; j < str[idx]->size(); j++){
                if((*str[idx])[j] != num){
                    *str[1-idx] += to_string(count) + to_string(num-48);
                    num = (*str[idx])[j];
                    count = 1;
                }else{
                    count++;
                }
            }
            *str[1-idx] += to_string(count) + to_string(num-48);
            idx = 1-idx;
            str[1-idx].reset(new string(""));
        }
        return *str[idx];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        string ret = Solution().countAndSay(n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}