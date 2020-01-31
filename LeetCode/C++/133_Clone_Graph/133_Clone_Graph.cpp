#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

/*
 * Definition for a Node.
 */
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        map<int, vector<int>> adjMap;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            node = q.front();
            q.pop();
            if(adjMap.find(node->val) != adjMap.end()) continue;
            vector<int> neighbors;
            for(auto t : node->neighbors){
                neighbors.push_back(t->val);
                q.push(t);
            }  
            adjMap[node->val] = neighbors;
        }

        vector<Node*> nodes;
        for(int i = 0; i < adjMap.size(); i++)
            nodes.push_back(new Node(i+1));
        for(int i = 0; i < adjMap.size(); i++)
            for(auto nodeVal : adjMap[i+1])
                nodes[i]->neighbors.push_back(nodes[nodeVal-1]);
        return nodes[0];
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

Node* stringToNode(string input){
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    stringstream ssList(input.substr(2, input.size()-4));
    vector<vector<int>> adjList;
    string item;
    char delimList(']');
    while(getline(ssList, item, delimList)){
        stringstream ssItem(item);
        string neighbor;
        char delimItem(',');
        vector<int> neighbors;
        while(getline(ssItem, neighbor, delimItem)){
            neighbors.push_back(stoi(neighbor));
        }
        adjList.push_back(neighbors);
        getline(ssList, item, '[');
    }

    vector<Node*> nodes;
    for(int i = 0; i < adjList.size(); i++)
        nodes.push_back(new Node(i+1));
    for(int i = 0; i < adjList.size(); i++)
        for(auto nodeVal : adjList[i])
            nodes[i]->neighbors.push_back(nodes[nodeVal-1]);

    return nodes.empty() ? NULL : nodes[0];
}

string nodeToString(Node* node){
    map<int, vector<int>> adjMap;
    queue<Node*> q;
    q.push(node);
    while(!q.empty()){
        node = q.front();
        q.pop();
        if(adjMap.find(node->val) != adjMap.end()) continue;
        vector<int> neighbors;
        for(auto t : node->neighbors){
            neighbors.push_back(t->val);
            q.push(t);
        }  
        adjMap[node->val] = neighbors;
    }

    string str("[");
    for(int i = 0; i < adjMap.size(); i++){
        str += "[";
        for(auto num : adjMap[i+1])
            str += to_string(num) + ", ";
        str += "], ";
    }
    str = str.substr(0, str.size()-2);
    str += "]";
    return str;
}

int main(void){
    while(true){
        string line;
        getline(cin, line);
        Node* graph = stringToNode(line);
        Node* clone = Solution().cloneGraph(graph);
        string str = nodeToString(clone);
        cout<<str<<endl;
    }
}