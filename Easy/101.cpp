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
    bool isSymmetric(TreeNode* root) {
        const function<TreeNode*(TreeNode*)> reflect = [&](TreeNode* a) -> TreeNode* {
            if (!a) return a;
            TreeNode* ret = new TreeNode(a->val);
            ret->left = reflect(a->right);
            ret->right = reflect(a->left);
            return ret;
        };
        const function<bool(TreeNode*, TreeNode*)> equal = [&](TreeNode* a, TreeNode* b) -> bool {
            if (!a || !b) return a == b;
            return a->val == b->val && equal(a->left, b->left) && equal(a->right, b->right);
        };
        return equal(root->left, reflect(root->right));
    }
};