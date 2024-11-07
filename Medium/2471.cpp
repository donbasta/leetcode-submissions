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
    int minimumOperations(TreeNode* root) {
        const int M = 1e5;
        vector<vector<int>> depth(M + 5);
        const function<void(TreeNode*, int)> dfs = [&](TreeNode* v, int d) {
            depth[d].push_back(v->val);
            if (v->left) dfs(v->left, d + 1);
            if (v->right) dfs(v->right, d + 1);
        };
        dfs(root, 0);
        int ans = 0;
        for (int i = 0; i < M; i++) {
            if (depth[i].empty()) break;
            vector<int> cp = depth[i];
            sort(cp.begin(), cp.end());
            map<int, int> mp;
            int idx = 0;
            for (auto e : cp) mp[e] = idx++;
            for (auto& e : depth[i]) e = mp[e];
            int sz = cp.size();
            vector<bool> vis(sz);
            for (int j = 0; j < sz; j++) {
                if (vis[depth[i][j]]) continue;
                int cur = depth[i][j];
                int len = 0;
                while (!vis[cur]) {
                    len++;
                    vis[cur] = true;
                    cur = depth[i][cur];
                }
                ans += (len - 1);
            }
        }
        return ans;
    }
};