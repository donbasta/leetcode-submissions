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
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        const function<pair<int, int>(TreeNode*)> dfs = [&](TreeNode* v) -> pair<int, int> {
            int mx = v->val, mn = v->val;
            if (v->left) {
                pair<int, int> L = dfs(v->left);
                ans = max(ans, abs(v->val - L.first));
                ans = max(ans, abs(v->val - L.second));
                mx = max(mx, L.second);
                mn = min(mn, L.first);
            }   
            if (v->right) {
                pair<int, int> R = dfs(v->right);
                ans = max(ans, abs(v->val - R.first));
                ans = max(ans, abs(v->val - R.second));
                mx = max(mx, R.second);
                mn = min(mn, R.first);
            }
            return make_pair(mn, mx);
        };
        dfs(root);
        return ans;
    }
};