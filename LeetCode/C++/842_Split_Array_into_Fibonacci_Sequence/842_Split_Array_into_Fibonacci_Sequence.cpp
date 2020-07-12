#include <assert.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void splitIntoFibonacci(const string& s, int j, vector<int>& res, const string& intMax){
        if(j == s.size())
            _res = res;
        for(int k = j+1; k <= s.size(); k++){
            string next = s.substr(j, k-j);
            if((s[j] == '0' && k-j != 1) || next.size() > intMax.size()
                    || (next.size() == intMax.size() && next > intMax))
                continue;
            // 缓存atoi结果
            int tmp = atoi(next.c_str());
            if(tmp - res[res.size()-1] == res[res.size()-2]){
                res.push_back(tmp);
                splitIntoFibonacci(s, k, res, intMax);
                res.pop_back();
            }  
        }
    }
    
    vector<int> splitIntoFibonacci(string S) {
        string intMax(to_string(INT_MAX));
        vector<int> res;
        // i,j,k都遵循前开后闭原则。
        for(int i = 1; i < static_cast<int>(S.size())-1; i++){
            // 缓存substr结果
            string first = S.substr(0, i);
            // 排除两种情况：一是以0开头且非0的数，二是first溢出。
            //
            //缓存INT_MAX的字符串intMax，当出现两种情况时溢出：一是first长度大于intMax，
            //二是长度相等但是在字符串比较中first更大。
            //
            // 字符串比较原则：按字符由前向后比较，字符较大者胜出，字符全部相等但长度更长者胜出。
            if((S[0] == '0' && i-0 != 1) || first.size() > intMax.size() 
                    || (first.size() == intMax.size() && first > intMax))
                continue;
            for(int j = i+1; j < S.size(); j++){
                string second = S.substr(i, j-i);
                if((S[i] == '0' && j-i != 1) || second.size() > intMax.size() 
                        || (second.size() == intMax.size() && second > intMax))
                    continue;
                res.push_back(atoi(first.c_str()));
                res.push_back(atoi(second.c_str()));
                splitIntoFibonacci(S, j, res, intMax);
                res.pop_back();
                res.pop_back();
            }
        }
        return _res;
    }
private:
    vector<int> _res;
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
        string S = stringToString(line);
        
        vector<int> ret = Solution().splitIntoFibonacci(S);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}