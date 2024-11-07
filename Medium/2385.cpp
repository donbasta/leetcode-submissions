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
    int amountOfTime(TreeNode* root, int start) {
        map<int, vector<int>> adj; 
        const function<void(TreeNode*)> dfs = [&](TreeNode* r) -> void {
            if (r->left) {
                adj[r->val].push_back(r->left->val);
                adj[r->left->val].push_back(r->val);
                dfs(r->left);
            }
            if (r->right) {
                adj[r->val].push_back(r->right->val);
                adj[r->right->val].push_back(r->val);
                dfs(r->right);
            }
        };
        dfs(root);
        int ans = 0;
        const function<void(int, int, int)> dfs_2 = [&](int v, int p, int dep) -> void {
            ans = max(ans, dep);
            for (auto c : adj[v]) {
                if (c == p) continue;
                dfs_2(c, v, dep + 1);
            }
        };
        dfs_2(start, -1, 0);
        return ans;
    }
};