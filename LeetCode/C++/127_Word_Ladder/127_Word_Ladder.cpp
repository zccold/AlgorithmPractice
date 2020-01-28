#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

class Solution {
private:
    map<string, vector<string>> wordDict;

public:
    int visitWordNode(map<string, int>& used1, map<string, int>& used2, queue<pair<string, int>>& q1){
        if(q1.empty()) return 0;

        string currentWord(q1.front().first);
        int len(q1.front().second);
        q1.pop();

        for(int i = 0; i < currentWord.size(); i++){
            string key = currentWord.substr(0, i) + "*" + currentWord.substr(i+1, currentWord.size()-i-1);
            for(auto word : wordDict[key]){
                if(used1.find(word) == used1.end()){
                    auto wordIteration(used2.find(word));
                    if(wordIteration != used2.end()){
                        return len + wordIteration->second;
                    }
                    q1.push(pair<string, int>(word, len+1));
                    used1[word] = len+1;
                }
            }
        }
        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;

        for(auto word : wordList){
            for(int i = 0; i < beginWord.size(); i++){
                string key = word.substr(0,i) + "*" + word.substr(i+1, word.size()-i-1);
                wordDict[key].push_back(word);
            }
        }

        queue<pair<string, int>> qTop, qBottom;
        qTop.push(pair<string, int>(beginWord, 1));
        qBottom.push(pair<string, int>(endWord, 1));
        map<string, int> usedTop{pair<string, int>(beginWord, 1)};
        map<string, int> usedBottom{pair<string, int>(endWord, 1)};
        
        int len;
        while(!qTop.empty() && !qBottom.empty()){
            len = visitWordNode(usedTop, usedBottom, qTop);
            if(len) return len;
            len = visitWordNode(usedBottom, usedTop, qBottom);
            if(len) return len;
        }
        return 0;
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

string stringToString(string& input){
    string res = input;
    trimLeftTrailingSpaces(res);
    trimRightTrailingSpaces(res);
    return res.substr(1, res.size()-2);
}

vector<string> stringToVectorString(string& input){
    string str = input;
    trimLeftTrailingSpaces(str);
    trimRightTrailingSpaces(str);
    stringstream ss(str.substr(1, str.size()-2));
    char delim(',');
    vector<string> res;
    while(getline(ss, str, delim)){
        res.push_back(str.substr(1, str.size()-2));
    }
    return res;
}

int main(void){
    while(true){
        string line;
        getline(cin, line);
        string beginWord = stringToString(line);
        getline(cin, line);
        string endWord = stringToString(line);
        getline(cin, line);
        vector<string> wordList = stringToVectorString(line);
        int len = Solution().ladderLength(beginWord, endWord, wordList);
        cout<<len<<endl;
    }
}