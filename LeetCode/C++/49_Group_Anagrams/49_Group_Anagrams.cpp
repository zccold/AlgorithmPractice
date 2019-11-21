#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    void countChar(string& str, string& count){
        vector<int> vi(26, 0);
        for(auto ch : str){
            vi[ch-'a']++;
        }
        for(auto i : vi){
            count += i;
        }
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> matchs;
        vector<vector<string>> res;
        for(auto str : strs){
            string count;
            countChar(str, count);
            matchs[count].push_back(str);
        }
        for(auto ptr = matchs.begin(); ptr != matchs.end(); ptr++)
            res.push_back(ptr->second);
        return res;
    }

    vector<vector<string>> groupAnagrams1(vector<string>& strs) {
        unordered_map<string, vector<string>> matchs;
        vector<vector<string>> res;
        for(auto str : strs){
            string cp = str;
            sort(cp.begin(), cp.end());
            matchs[cp].push_back(str);
        }
        for(auto ptr = matchs.begin(); ptr != matchs.end(); ptr++)
            res.push_back(ptr->second);
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

vector<string> stringToVectorString(string line){
    vector<string> vs;
    trimLeftTrailingSpaces(line);
    trimRightTrailingSpaces(line);
    stringstream ss(line.substr(1, line.size()-2));
    string item;
    char delim = ',';
    while(getline(ss, item, delim))
        vs.push_back(item.substr(1, item.size()-2));
    return vs;
}

string VectorVectorStringToString(vector<vector<string>>& vvs){
    string str("[");
    for(auto vs : vvs){
        str += "\n\t[";
        for(auto s : vs){
            str += "\"" + s + "\",";
        }
        str.erase(str.end()-1);
        str += "],";
    }
    str.erase(str.end()-1);
    str += "\n]\n";
    return str;
}

int main(void){
    while(true){
        string line;
        getline(cin, line);
        vector<string> vs = stringToVectorString(line);
        vector<vector<string>> vvs = Solution().groupAnagrams(vs);
        cout<<VectorVectorStringToString(vvs);
    }
}