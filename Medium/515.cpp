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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return vector<int>{};
        const int M = 1e4;
        vector<int> ve(M, INT_MIN);
        int depth = 0;

        const function<void(TreeNode*, int)> solve = [&](TreeNode* v, int d) {
            depth = max(depth, d);
            ve[d] = max(ve[d], v->val);
            if (v->left) solve(v->left, d + 1);
            if (v->right) solve(v->right, d + 1);
        };

        solve(root, 0);
        ve.resize(depth + 1);
        return ve;
    }
};