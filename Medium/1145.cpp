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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        vector<vector<int>> ch(n + 1);
        vector<int> sz(n + 1);
        function<void(TreeNode*)> dfs = [&](TreeNode* v) {
            sz[v->val] = 1;
            if (v->left) {
                ch[v->val].push_back(v->left->val);
                dfs(v->left);
                sz[v->val] += sz[v->left->val];
            }
            if (v->right) {
                ch[v->val].push_back(v->right->val);
                dfs(v->right);
                sz[v->val] += sz[v->right->val];
            }
        };
        dfs(root);
        int mx = 0;
        for (auto c : ch[x]) {
            mx = max(mx, sz[c]);
        }
        if (x != root->val) {
            mx = max(mx, n - sz[x]);
        }
        return mx > n - mx;
    }
};