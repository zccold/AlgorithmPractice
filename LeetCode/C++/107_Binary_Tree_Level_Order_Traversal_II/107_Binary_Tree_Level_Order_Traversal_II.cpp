#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        vector<vector<int>> res;
        queue<TreeNode*> q(deque<TreeNode*>{root, NULL});
        vector<int> level;
        while(true){
            TreeNode* node = q.front();
            q.pop();
            if(!node){
                res.push_back(level);
                while(!level.empty()) level.pop_back();
                if(q.empty()) break;
                q.push(NULL);
                continue;
            }
            level.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                    return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                    return !isspace(ch);
                })
                    .base(),
                input.end());
}

TreeNode *stringToTreeNode(string input)
{
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size())
    {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true)
    {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string vectorVectorIntToString(vector<vector<int>> input)
{
    string str("[\n");
    for(auto vi : input){
        str += "\t[";
        for(auto i : vi){
            str += to_string(i)+", ";
        }
        str = str.substr(0, str.size()-2);
        str += "],\n";
    }
    str = str.substr(0, str.size()-2);
    str += "\n]\n";
    return str;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        TreeNode *root = stringToTreeNode(line);

        vector<vector<int>> ret = Solution().levelOrderBottom(root);

        string out = vectorVectorIntToString(ret);
        cout << out << endl;
    }
    return 0;
}