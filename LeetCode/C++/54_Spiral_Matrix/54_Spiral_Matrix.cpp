#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int left, right, top, bottom;
        left = top = 0, right = matrix[0].size()-1, bottom = matrix.size()-1;
        int i = 0, j = 0;
        while(left <= right && top <= bottom){
            while(j <= right){
                res.push_back(matrix[i][j++]);
            }
            j--, i++;
            if(i <= bottom){
                while(i <= bottom){
                    res.push_back(matrix[i++][j]);
                }
                i--, j--;
            }else{
                break;
            }
            if(j >= left){
                while(j >= left){
                    res.push_back(matrix[i][j--]);
                }
                j++, i--;
            }else{
                break;
            }
            if(i > top){
                while(i > top){
                    res.push_back(matrix[i--][j]);
                }
                i++, j++;
                left++, top++, right--, bottom--;
            }else{
                break;
            }   
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

string VectorIntToString(vector<int>& vi){
    string str("[");
    for(auto i : vi){
        str += to_string(i) + ",";
    }
    str.erase(str.end()-1);
    str += "]\n";
    return str;
}

int main(void){
    while(true){
        string line;
        getline(cin, line);
        vector<vector<int>> matrix = stringToVectorVectorInt(line);
        vector<int> res = Solution().spiralOrder(matrix);
        cout<<VectorIntToString(res);
    }
}