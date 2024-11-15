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
    bool isUnivalTree(TreeNode* root) {
        bool ok = true;
        if (root->left) {
            ok &= (root->val == root->left->val);
            ok &= isUnivalTree(root->left);
        }
        if (root->right) {
            ok &= (root->val == root->right->val);
            ok &= isUnivalTree(root->right);
        }
        return ok;
    }
};