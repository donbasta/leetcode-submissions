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
    int goodNodes(TreeNode* root) {
        int ans = 1;
        const function<void(TreeNode*, int)> dfs = [&](TreeNode* v, int mx) {
            if (v->left) ans += v->left->val >= mx, dfs(v->left, max(mx, v->left->val));
            if (v->right) ans += v->right->val >= mx, dfs(v->right, max(mx, v->right->val));
        };
        dfs(root, root->val);
        return ans;
    }
};