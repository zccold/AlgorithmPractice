#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

/*
// Definition for a Node.
 */

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(NULL == root || NULL == root->left) return root;
        Node *f = root, *s = NULL;
        while(f->left){
            s = f;
            s->left->next = s->right;
            while(s->next){
                s->right->next = s->next->left;
                s = s->next;
                s->left->next = s->right;
            }
            f = f->left;
        }
        return root;
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

Node* stringToNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    Node* root = new Node(stoi(item));
    queue<Node*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        Node* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new Node(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new Node(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string nodeToString(Node* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* node = q.front();
        q.pop();

        output += to_string(node->val) + ", ";
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        Node* root = stringToNode(line);
        
        Solution().connect(root);

        string out = nodeToString(root);
        cout << out << endl;
    }
    return 0;
}