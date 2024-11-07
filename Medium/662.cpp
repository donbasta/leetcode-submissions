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
    int widthOfBinaryTree(TreeNode* root) {
        using ll = long long;
        const ll INF = 1e18;
        vector<ll> L(3001, INF), R(3001, -INF);
        const ll MOD = 1e10;
        const function<void(TreeNode*, ll, int)> dfs = [&](TreeNode* v, ll label, int depth) {
            L[depth] = min(L[depth], label);
            R[depth] = max(R[depth], label);
            if (v->left) {
                dfs(v->left, 2ll * label % MOD, depth + 1);
            } 
            if (v->right) {
                dfs(v->right, (2ll * label + 1) % MOD, depth + 1);
            }
        };
        dfs(root, 1, 0);
        ll ans = 1;
        for (int i = 1; i <= 3000; i++) {
            if (L[i] == INF) break;
            ll tmp = (R[i] - L[i] + 1) % MOD;
            if (tmp < 0) tmp += MOD;
            ans = max(ans, tmp);
        }
        return ans;
    }
};