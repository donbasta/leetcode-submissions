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
    int distributeCoins(TreeNode* root) {
        int ret = 0;
        const function<int(TreeNode*)> dfs = [&](TreeNode* v) -> int {
            if (!v) return 0;
            int left = dfs(v->left);
            int right = dfs(v->right);
            ret += abs(left) + abs(right);
            return v->val + left + right - 1;
        };

        assert (dfs(root) == 0);
        return ret;
    }
};