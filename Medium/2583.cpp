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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        const int MX = 1e5;
        const int INF = 2e9;
        vector<long long> ve(MX + 1, 0);
        const function<void(TreeNode*, int)> dfs = [&](TreeNode* v, int depth) -> void {
            if (!v) return;
            ve[depth] += v->val;
            dfs(v->left, depth + 1), dfs(v->right, depth + 1);
        };
        dfs(root, 0);
        sort(ve.begin(), ve.end(), greater<>());
        long long ans = ve[k - 1];
        if (ans == 0) ans = -1;
        return ans;
    }
};