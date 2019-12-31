#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <algorithm>

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

class Solution {
public:
    void recursive(TreeNode* root, int sum, vector<int> path, vector<vector<int>>& res) {
        if(!root){
            if(sum == 0) res.push_back(path);
            return;
        } 
        sum -= root->val;
        path.push_back(root->val);

        if(!root->left){
            recursive(root->right, sum, path, res);
        }else if(!root->right){
            recursive(root->left, sum, path, res);
        }else{
            recursive(root->left, sum, path, res);
            recursive(root->right, sum, path, res);
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return vector<vector<int>>();
        vector<vector<int>> res;
        recursive(root, sum, vector<int>(), res);
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

TreeNode* stringToTreeNode(string input) {
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
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int stringToInteger(string input) {
    return stoi(input);
}

string vectorVectorIntToString(vector<vector<int>>& vvi){
    string str("[");
    for(auto vi : vvi){
        str += "\n\t[";
        for(auto i : vi){
            str += to_string(i) + ",";
        }
        str.erase(str.end()-1);
        str += "],";
    }
    str.erase(str.end()-1);
    str += "\n]";
    return str;
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int sum = stringToInteger(line);
        
        vector<vector<int>> ret = Solution().pathSum(root, sum);

        string out = vectorVectorIntToString(ret);
        cout << out << endl;
    }
    return 0;
}