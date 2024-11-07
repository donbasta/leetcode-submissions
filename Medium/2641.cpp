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
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int, int> sum_all;
        unordered_map<TreeNode*, int> sum_children;
        const function<void(TreeNode*, int)> dfs = [&](TreeNode* r, int depth) -> void {
            if (!r) return;
            sum_all[depth] += r->val;
            if (r->left) sum_children[r] += r->left->val;
            if (r->right) sum_children[r] += r->right->val;
            dfs(r->left, depth + 1);
            dfs(r->right, depth + 1);
        };
        const function<void(TreeNode*, int)> dfs_upd = [&](TreeNode* r, int depth) -> void {
            if (!r) return;
            if (r->left) r->left->val = sum_all[depth + 1] - sum_children[r];
            if (r->right) r->right->val = sum_all[depth + 1] - sum_children[r];
            dfs_upd(r->left, depth + 1);
            dfs_upd(r->right, depth + 1);
        };
        dfs(root, 0);
        dfs_upd(root, 0);
        root->val = 0;
        return root;
    }   
};