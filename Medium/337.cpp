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
    int rob(TreeNode* root) {
        function<pair<int, int>(TreeNode*)> dfs = [&](TreeNode* v) -> pair<int, int> {
            pair<int, int> l = make_pair(0, 0), r = make_pair(0, 0);
            if (v->left) { 
                l = dfs(v->left);
            }
            if (v->right) {
                r = dfs(v->right);
            }
            return make_pair(max(l.first, l.second) + max(r.first, r.second), v->val + l.first + r.first);
        };
        return max(dfs(root).first, dfs(root).second);
    }
};