#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows < 1) return vector<vector<int>>();
        vector<vector<int>> res{vector<int>{1}};
        for(int i = 0; i < numRows-1; i++){
            vector<int> theRow;
            for(int j = 0; j < res[i].size(); j++){
                if(j != 0){
                    theRow.push_back(res[i][j]+res[i][j-1]);
                }else{
                    theRow.push_back(res[i][j]);
                }
            }
            theRow.push_back(1);
            res.push_back(theRow);
        }
        return res;
    }
};

string vectorVectorIntToString(vector<vector<int>>& vvi){
    string str("[\n");
    for(auto vi : vvi){
        str += "\t[";
        for(auto num : vi){
            str += to_string(num) + ", ";
        }
        str = str.substr(0, str.size()-2);
        str += "],\n";
    }
    str = str.substr(0, str.size()-2);
    str += "\n]";
    return str;
}

int main(void){
    string line;
    while(true){
        getline(cin, line);
        int numRows = stoi(line);
        vector<vector<int>> res = Solution().generate(numRows);
        string str = vectorVectorIntToString(res);
        cout<<str<<endl;
    }
}