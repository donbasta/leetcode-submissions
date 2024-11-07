/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
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
        vector<int> ret;
        const function<void(int, int, int)> dfs_2 = [&](int v, int p, int dep) -> void {
            if (dep == k) {
                ret.push_back(v);
                return;
            }
            for (auto c : adj[v]) {
                if (c == p) continue;
                dfs_2(c, v, dep + 1);
            }
        };
        dfs_2(target->val, -1, 0);
        return ret;
    }
};