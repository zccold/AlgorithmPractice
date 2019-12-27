#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode* buildTree(vector<int>& inorder, int inl, vector<int>& postorder, int postl, int len){
        if(len == 0) return NULL;
        
        TreeNode* node = new TreeNode(postorder[postl+len-1]);
        if(len == 1) return node;
        
        int idx = find(inorder.begin()+inl, inorder.begin()+inl+len, postorder[postl+len-1]) - inorder.begin();
        node->left = buildTree(inorder, inl, postorder, postl, idx-inl);
        node->right = buildTree(inorder, idx+1, postorder, postl+idx-inl, inl+len-1-idx);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        return buildTree(inorder, 0, postorder, 0, inorder.size());
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

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> inorder = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> postorder = stringToIntegerVector(line);
        
        TreeNode* ret = Solution().buildTree(inorder, postorder);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}