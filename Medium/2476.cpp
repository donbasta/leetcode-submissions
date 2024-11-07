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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> all;
        const function<void(TreeNode*)> dfs = [&](TreeNode* tree) -> void {
            if (!tree) return;
            dfs(tree->left);
            all.push_back(tree->val);
            dfs(tree->right);
        };
        dfs(root);
        vector<vector<int>> ret;
        int n = all.size();
        for (auto q : queries) {
            int idx = lower_bound(all.begin(), all.end(), q) - all.begin();
            int mn = -1, mx = -1;
            if (idx < n && all[idx] == q) {
                mn = mx = q;
            } else if (idx < n && all[idx] > q) {
                mx = all[idx];
                if (idx > 0) mn = all[idx - 1];
            } else if (idx == n) {
                mn = all[idx - 1];
            }
            ret.push_back({mn, mx});
        }
        return ret;
    }
};