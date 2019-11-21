#include <iostream>
#include <string>
#include <assert.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> num(num1.size()+num2.size(), 0);
        for(int i = num1.size()-1; i >= 0; i--){
            for(int j = num2.size()-1; j >= 0; j--){
                int sum = (num1[i]-48)*(num2[j]-48) + num[i+j+1];
                div_t d = div(sum ,10);
                num[i+j] += d.quot;
                num[i+j+1] = d.rem;
            }
        }
        string res;
        for(auto n : num){
            if(res.size() || n) res += n+48;
        }
        return res;
    }

    string multiply(const string& num1, const char num2){
        string pro;
        div_t d;
        int carry = 0;
        for(auto ptr = num1.rbegin(); ptr != num1.rend(); ptr++){
            d = div(carry + (*ptr - 48)*(num2 - 48), 10);
            pro.insert(0, 1, d.rem+48);
            carry = d.quot;
        }
        if(carry) pro.insert(0, 1, carry+48);
        return pro;
    }

    string add(const string& num1, const string& num2){
        string cal;
        div_t d;
        int carry = 0;
        auto ptr1 = num1.rbegin(), ptr2 = num2.rbegin();
        for(;
            ptr1 != num1.rend() && ptr2 != num2.rend();
            ptr1++, ptr2++){
            d = div(carry + (*ptr1 - 48) + (*ptr2 - 48), 10);
            cal.insert(0, 1, d.rem+48);
            carry = d.quot;
        }
        if(carry == 0){
            if(ptr1 != num1.rend())
                cal.insert(cal.begin(), num1.begin(), ptr1.base());
            if(ptr2 != num1.rend())
                cal.insert(cal.begin(), num2.begin(), ptr2.base());
        }else{
            for(; ptr1 != num1.rend(); ptr1++){
                d = div(carry + (*ptr1 - 48), 10);
                cal.insert(0, 1, d.rem+48);
                carry = d.quot;
            }
            for(; ptr2 != num2.rend(); ptr2++){
                d = div(carry + (*ptr2 - 48), 10);
                cal.insert(0, 1, d.rem+48);
                carry = d.quot;
            }
        }
        if(carry) cal.insert(0, 1, carry+48);
        return cal;
    }

    string multiply1(string num1, string num2) {
        string res;
        int count = 0;
        for(auto ptr = num1.rbegin(); ptr != num1.rend(); ptr++){
            string tmp = multiply(num2, *ptr);
            tmp.insert(tmp.size(), count++, '0');
            res = add(tmp, res);
        }   
        res.erase(res.begin(), find_if(res.begin(), res.end(), [](char ch){
            return ch != '0';
        }));
        if(res.size() == 0) res += "0";
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
        string num1 = stringToString(line);
        getline(cin, line);
        string num2 = stringToString(line);
        
        string ret = Solution().multiply(num1, num2);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}