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
    int maxLevelSum(TreeNode* root) {
        unordered_map<int, int> ump;
        const function<void(TreeNode*, int)> dfs = [&](TreeNode* v, int depth) -> void {
            ump[depth] += v-> val;
            if (v->left) dfs(v->left, depth + 1);
            if (v->right) dfs(v->right, depth + 1);
        };
        dfs(root, 1);
        const int INF = 2e9;
        int mx = -INF;
        for (auto e : ump) {
            mx = max(mx, e.second);
        }
        int mn = INF;
        for (auto e : ump) {
            if (e.second == mx && e.first < mn) {
                mn = e.first;
            }
        }
        return mn;
    }
};