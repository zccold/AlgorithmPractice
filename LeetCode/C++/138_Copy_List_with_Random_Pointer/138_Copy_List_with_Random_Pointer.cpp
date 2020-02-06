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
/* Definition for a Node.
*/
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *cur(head), *copy(NULL);
        while(cur){
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }
        cur = head;
        while(cur){
            copy = cur->next;
            if(NULL != cur->random)
                copy->random = cur->random->next;
            cur = copy->next;
        }
        cur = head;
        Node copyHead(0);
        copy = &copyHead;
        while(cur){
            copy->next = cur->next;
            copy = copy->next;
            cur->next = copy->next;
            cur = cur->next;
        }

        return copyHead.next;
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
    vector<vector<int>> data;
    string item;
    char delimList(']');
    while(getline(ssList, item, delimList)){
        stringstream ssItem(item);
        string s;
        char delimItem(',');
        vector<int> valAndRandom;
        while(getline(ssItem, s, delimItem)){
            if(s == "null")
                valAndRandom.push_back(-1);
            else 
                valAndRandom.push_back(stoi(s));
        }
        data.push_back(valAndRandom);
        getline(ssList, item, '[');
    }

    vector<Node*> nodes;
    for(int i = 0; i < data.size(); i++)
        nodes.push_back(new Node(data[i][0]));
    for(int i = 0; i < data.size(); i++){
        if(data[i][1] != -1) nodes[i]->random = nodes[data[i][1]];
        if(i+1 != data.size()) nodes[i]->next = nodes[i+1];
    }

    return nodes.empty() ? NULL : nodes[0];
}

int findRandomIdx(Node* head, Node* cur){
    if(NULL == cur->random) return -1;
    int idx = 0;
    while(head != cur->random){
        head = head->next;
        idx++;
    }
    return idx;
}

string nodeToString(Node* node){
    vector<vector<int>> nodes;
    Node* head = node;
    while(node){
        vector<int> valAndRandom{node->val};
        valAndRandom.push_back(findRandomIdx(head, node));
        nodes.push_back(valAndRandom);
        node = node->next;
    }

    string str("[");
    for(int i = 0; i < nodes.size(); i++){
        str += "[" + to_string(nodes[i][0]) + ", ";
        if(-1 == nodes[i][1])
            str += "null], ";
        else
            str += to_string(nodes[i][1]) + "], ";
    }
    str = str.substr(0, str.size()-2);
    str += "]";
    return str;
}

int main() {
    string line;
    while (getline(cin, line)) {
        Node* head = stringToNode(line);
        
        Node* copy = Solution().copyRandomList(head);

        string out = nodeToString(copy);
        cout << out << endl;
    }
    return 0;
}