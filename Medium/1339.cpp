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
    int maxProduct(TreeNode* root) {
        unordered_map<TreeNode*, long long> ump;
        const function<void(TreeNode*)> dfs = [&](TreeNode* v) {
            ump[v] += v->val;
            if (v->left) dfs(v->left), ump[v] += ump[v->left];
            if (v->right) dfs(v->right), ump[v] += ump[v->right];
        };
        dfs(root);
        long long ans = 0;
        for (auto c : ump) {
            if (c.first != root) {
                ans = max(ans, c.second * (ump[root] - c.second));
            }
        }
        const int MOD = 1e9+ 7;
        return ans % MOD;
    }
};