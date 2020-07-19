#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int l = 0, r = A.size()-1;
        int neg = -1;
        while(r - l > 1){
            int mid = (l+r)/2;
            if(A[mid] >= 0){
                r = mid-1;
            }else{
                l = mid;
            }
        }
        neg = (A[r] < 0) ? r : ((A[l] < 0) ? l : -1);
        
        vector<int> res;
        int notNeg = neg+1;
        while(neg >= 0 && notNeg < A.size()){
            if(-A[neg] <= A[notNeg]){
                res.push_back(pow(A[neg], 2));
                neg--;
            }else{
                res.push_back(pow(A[notNeg], 2));
                notNeg++;
            }
        }
        while(neg >= 0){
            res.push_back(pow(A[neg], 2));
            neg--;
        }
        while(notNeg < A.size()){
            res.push_back(pow(A[notNeg], 2));
            notNeg++;
        }
        return res;
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

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
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
        vector<int> A = stringToIntegerVector(line);
        
        vector<int> ret = Solution().sortedSquares(A);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}