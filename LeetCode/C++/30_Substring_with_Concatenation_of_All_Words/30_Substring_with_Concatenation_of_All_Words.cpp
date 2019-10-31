#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words){
        if(!s.size() || !words.size())
            return vector<int>();
        
        vector<int> res;
        unordered_map<string, int> match;
        for(auto word : words)
            match[word]++;
        int lens, n, lenWord;
        lens = s.size(), n = words.size(), lenWord = words[0].size();
        for(int i = 0; i < lens - n*lenWord + 1; i++){
            int j = 0;
            unordered_map<string, int> m(match);
            for( ; j < n; j++){
                string tmp = s.substr(i + j*lenWord, lenWord);
                if(m.find(tmp) != m.end() && m[tmp])
                    m[tmp]--;
                else
                    break;
            }
            if(j == n) res.push_back(i);
        }
        return res;
    }
};

void trimLeftTrailingSpaces(string &line)
{
    line.erase(line.begin(), find_if(line.begin(), line.end(), [](int ch) {
                   return !isspace(ch);
               }));
}

void trimRightTrailingSpaces(string &line)
{
    line.erase(find_if(line.rbegin(), line.rend(), [](char ch) {
                   return !isspace(ch);
               })
                   .base(),
               line.end());
}

string stringToString(string &line)
{
    trimLeftTrailingSpaces(line);
    trimRightTrailingSpaces(line);
    return line.substr(1, line.size() - 2);
}

vector<string> stringToVectorString(string &line)
{
    vector<string> res;
    trimLeftTrailingSpaces(line);
    trimRightTrailingSpaces(line);
    stringstream ss(line.substr(1, line.size() - 2));
    string item;
    char delim = ',';
    while (getline(ss, item, delim))
        res.push_back(item.substr(1, item.size() - 2));
    return res;
}

string vectorStringToString(vector<int> &res)
{
    string str;
    for (auto t : res)
        str += to_string(t);
    return str;
}

int main(void)
{
    string line;
    while (getline(cin, line))
    {
        string s = stringToString(line);

        getline(cin, line);

        vector<string> words = stringToVectorString(line);

        vector<int> res = Solution().findSubstring(s, words);
        string str = vectorStringToString(res);
        cout << str << endl;
    }
}