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
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        function<pair<int, int>(TreeNode*)> dfs = [&](TreeNode* v) -> pair<int, int> {
            int X = 0, Y = 0;
            if (v->left) {
                pair<int, int> L = dfs(v->left);
                ans = max(ans, 1 + L.second);
                X = 1 + L.second;
            }
            if (v->right) {
                pair<int, int> R = dfs(v->right);
                ans = max(ans, 1 + R.first);
                Y = 1 + R.first;
            }
            return make_pair(X, Y);
        };

        dfs(root);
        return ans;
    }
};