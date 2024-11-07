/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string tree2str(TreeNode* root) {
        string ret = to_string(root->val);
        if (root->left && root->right) {
            ret += '(';
            ret += tree2str(root->left);
            ret += ')';
            ret += '(';
            ret += tree2str(root->right);
            ret += ')';
        } else if (root->left) {
            ret += '(';
            ret += tree2str(root->left);
            ret += ')';
        } else if (root->right) {
            ret += "()";
            ret += '(';
            ret += tree2str(root->right);
            ret += ')';
        }
        return ret;
    }
};