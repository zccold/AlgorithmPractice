#include <iostream>
#include <vector>

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
    vector<TreeNode*> generateTrees(int l, int r){
        vector<TreeNode*> nodes, lefts, rights;
        if(l <= r){
            for(int i = l; i <= r; i++){
                lefts = generateTrees(l, i-1);
                rights = generateTrees(i+1, r);
                for(auto left : lefts){
                    for(auto right : rights){
                        TreeNode* node = new TreeNode(i);
                        node->left = left;
                        node->right = right;
                        nodes.push_back(node);
                    }
                }   
            }
        }else{
            nodes.push_back(NULL);
        }
        return nodes;
    }

    vector<TreeNode *> generateTrees(int n)
    {
        if(n <= 0) return vector<TreeNode*>();
        return generateTrees(1, n);
    }
};

void preorder(string& str, TreeNode* node){
    if(node){
        str += to_string(node->val);
        str += ", ";
        preorder(str, node->left);
        preorder(str, node->right);
    }
}

void vectorTreeToString(string& str, vector<TreeNode*>& vtn){
    str += "[\n";
    for(auto node : vtn){
        str += "\t[";
        preorder(str, node);
        str = str.substr(0, str.size()-2);
        str += "],\n";
    }
    str = str.substr(0, str.size()-2);
    str += "\n]\n";
}

int main(){
    while(true){
        string str;
        getline(cin, str);
        int n = stoi(str);
        vector<TreeNode*> res = Solution().generateTrees(n);
        string out;
        vectorTreeToString(out, res);
        cout<<out<<endl;
    }
}