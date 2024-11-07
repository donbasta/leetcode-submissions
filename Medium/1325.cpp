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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        const function<TreeNode*(TreeNode*)> dfs = [&](TreeNode* v) -> TreeNode* {
            if (v->left) v->left = dfs(v->left);
            if (v->right) v->right = dfs(v->right);
            if (!v->left && !v->right && v->val == target) return nullptr;
            return v;
        };
        return dfs(root);
    }
};