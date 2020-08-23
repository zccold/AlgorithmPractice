#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Compare {
public:
    bool operator()(pair<vector<int>, vector<string>> a, pair<vector<int>, vector<string>> b) {
        return a.first[2] > b.first[2];
    }
};

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // 第一处优化：提前计算所有word的距离并缓存
        int endWordIdx = 0;
        for(int i = 0; i < wordList.size(); i++) {
            if(wordList[i] == endWord) {
                endWordIdx = i;
            }
        }
        vector<vector<int>> distance(wordList.size()+1, vector<int>(wordList.size()+1, 0));
        for(int i = 0; i < wordList.size()+1; i++) {
            for(int j = 0; j < wordList.size()+1; j++) {
                string tmp = beginWord;
                if(i != 0) tmp = wordList[i-1];
                if(i < j)
                    distance[i][j] = calcDistance(tmp, wordList[j-1]);
                else
                    distance[i][j] = distance[j][i];
            }
        }
        // auto cmp = [](pair<vector<int>, vector<string>> a, pair<vector<int>, vector<string>> b) {
        //     return a.first[2] > b.first[2];
        // };
        priority_queue<pair<vector<int>, vector<string>>, vector<pair<vector<int>, vector<string>>>, Compare> pathQueue;
        int sufCost = distance[0][endWordIdx];
        pathQueue.push(pair<vector<int>, vector<string>>(vector<int>{1, sufCost, sufCost+1, 0}, vector<string>{beginWord}));
        vector<vector<string>> res;
        while(!pathQueue.empty()) {
            pair<vector<int>, vector<string>> curPath = pathQueue.top();
            pathQueue.pop();
            if(curPath.second.back() == endWord && (res.empty() || curPath.first[2] == res.back().size())) {
                res.push_back(curPath.second);
            } 
            if(!res.empty() && curPath.first[2] > res.back().size()) {
                return res;
            }
            for(int i = 1; i < wordList.size()+1; i++) {
                int j = curPath.first[3];
                if(distance[i][j] == 1) {
                    string& word = wordList[i-1];    
                    vector<string>& tmp = curPath.second;
                    if(find(tmp.begin(), tmp.end(), word) == tmp.end()) {
                        int curCost = curPath.first[0]+1;
                        int sufCost = distance[i][endWordIdx+1];
                        tmp.push_back(word);
                        pathQueue.push(pair<vector<int>, vector<string>>(vector<int>{curCost, sufCost, curCost+sufCost, i}, tmp));
                        tmp.pop_back();
                    }
                }
            }
        }
        return res;
    }
private:
    int calcDistance(const string& a, const string& b) {
        int distance = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) {
                distance++;
            }
        }
        return distance;
    }
};

void trimLeft(string& input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](char ch){
        return isspace(ch);
    }));
}

void trimRight(string& input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](char ch){
        return isspace(ch);
    }).base(), input.end());
}

vector<string> stringToVectorString(string input) {
    stringstream ss(input.substr(2, input.size()-4));
    string item;
    char delim('"');
    vector<string> res;
    while(getline(ss, item, delim)) {
        res.push_back(item);
        getline(ss, item, delim);
    }
    return res;
}

string vectorVectorStringToString(vector<vector<string>>& vvs) {
    string res("[\n");
    for(auto vs : vvs) {
        res += "\t[";
        for(auto str : vs) {
            res += "\"" + str + "\",";
        }
        res.erase(--res.end());
        res += "],\n";
    }
    res.erase(res.end()-2);
    res += "\n]";
    return res;
}

int main() {
    string line;
    while (true) {
        getline(cin, line);
        string beginWord = line.substr(1, line.size()-2);

        getline(cin, line);
        string endWord = line.substr(1, line.size()-2);

        getline(cin, line);
        vector<string> wordList = stringToVectorString(line);

        vector<vector<string>> out = Solution().findLadders(beginWord, endWord, wordList);
        cout << vectorVectorStringToString(out) << endl;
    }
    return 0;
}