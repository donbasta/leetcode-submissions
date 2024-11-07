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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        function<int(TreeNode*&, int)> dfs = [&](TreeNode*& v, int cur) -> int {
            int mx = INT_MIN;
            if ((!v->left) && (!v->right)) {
                mx = v->val;
            }
            if (v->left) {
                int tmp = dfs(v->left, cur + v->val);
                mx = max(mx, tmp + v->val);
            }
            if (v->right) {
                int tmp = dfs(v->right, cur + v->val);
                mx = max(mx, tmp + v->val);
            }
            if (mx + cur < limit) {
                v = nullptr;
            }
            return mx;
        };
        dfs(root, 0);
        return root;
    }
};