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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> cnt;
        const function<void(TreeNode*)> dfs = [&](TreeNode* v) -> void {
            if (!v) return;
            cnt[v->val]++;
            dfs(v->left);
            dfs(v->right);
        };
        dfs(root);
        int mx = 0;
        for (auto e : cnt) mx = max(mx, e.second);
        vector<int> ret;
        for (auto e : cnt) if (e.second == mx) ret.push_back(e.first);
        return ret;
    }
};