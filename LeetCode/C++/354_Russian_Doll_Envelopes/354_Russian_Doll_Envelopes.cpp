#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size() < 2)
            return envelopes.size();
        sort(envelopes.begin(), envelopes.end(), 
             // 技巧：以num[0]排升序时，若两个数num[0]相等，应该以num[1]排降序。
             // 这样后续tag处就不需要判断num[0]是否也满足大于。
             [](const vector<int>& vi1, const vector<int>& vi2){ 
                 if(vi1[0] < vi2[0]){
                     return true;
                 }else if(vi1[0] == vi2[0]){
                     return (vi1[1] > vi2[1]) ? true : false;
                 }else{
                     return false;
                 }
             });
        vector<int> dp(envelopes.size(), 1);
        int maxLen = 1;
        int i = 1;
        while(i < envelopes.size()){
            int curLen = 0;
            for(int j = i-1; j >= 0; j--){
                // tag
                if(envelopes[i][1] > envelopes[j][1])
                    curLen = max(curLen, dp[j]);
            }
            dp[i] = curLen+1;
            maxLen = max(maxLen, dp[i]);
            i++;
        }
        return maxLen;
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

vector<vector<int>> stringToVectorVectorInt(string input) {
    vector<vector<int>> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(2, input.length() - 4);
    stringstream ssVV;
    ssVV.str(input);
    string itemV;
    char delimVV = ']';
    while (getline(ssVV, itemV, delimVV)) {
        vector<int> vi;
        stringstream ssV(itemV);
        string item;
        char delimV = ',';
        while(getline(ssV, item, delimV))
            vi.push_back(stoi(item));
        output.push_back(vi);
        getline(ssVV, itemV, '[');
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<vector<int>> envelopes = stringToVectorVectorInt(line);
        
        int ret = Solution().maxEnvelopes(envelopes);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}