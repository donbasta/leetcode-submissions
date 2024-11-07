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
    int findBottomLeftValue(TreeNode* root) {
        pair<int, int> T = make_pair(-1, -1);
        const function<void(TreeNode*, int)> dfs = [&](TreeNode* v, int depth) {
            if (depth >= T.first) {
                T = make_pair(depth, v->val);
            }
            if (v->right) dfs(v->right, depth + 1);
            if (v->left) dfs(v->left, depth + 1);
        };
        dfs(root, 0);
        return T.second;
    }
};