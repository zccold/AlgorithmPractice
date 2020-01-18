#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;

        vector<int> res(triangle.size(), triangle[0][0]);
        for(int i = 1; i < triangle.size(); i++){
            for(int j = i; j >= 0; j--){
                int minSum = INT_MAX;
                if(j <= i-1) minSum = min(res[j], minSum);
                if(j-1 >= 0) minSum = min(res[j-1], minSum);
                res[j] = minSum + triangle[i][j];
            }
        }
        return *min_element(res.begin(), res.end());
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

vector<int> stringToVectorInt(string line){
    vector<int> vi;
    stringstream ss(line);
    string item;
    char delim = ',';
    while(getline(ss, item, delim))
        vi.push_back(stoi(item));
    return vi;
}

vector<vector<int>> stringToVectorVectorInt(string line){
    vector<vector<int>> vvi;
    trimLeftTrailingSpaces(line);
    trimRightTrailingSpaces(line);
    stringstream ss(line.substr(2, line.size()-4));
    string item;
    char delim = ']';
    while(getline(ss, item, delim)){
        vvi.push_back(stringToVectorInt(item));
        getline(ss, item, '[');
    }     
    return vvi;
}

int main(void){
    while(true){
        string line;
        getline(cin, line);
        vector<vector<int>> triangle = stringToVectorVectorInt(line);
        int minPath = Solution().minimumTotal(triangle);
        cout<<minPath<<endl;
    }
}