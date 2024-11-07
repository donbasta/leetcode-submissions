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
    TreeNode* reverseOddLevels(TreeNode* root) {
        const int M = 1e5;
        vector<vector<TreeNode*>> nodes(M + 5);
        vector<vector<int>> vals(M + 5);
        const function<void(TreeNode*, int)> dfs = [&](TreeNode* v, int depth) {
            nodes[depth].push_back(v);
            vals[depth].push_back(v->val);
            if (v->left) dfs(v->left, depth + 1);
            if (v->right) dfs(v->right, depth + 1);
        };
        dfs(root, 0);
        for (int i = 0; i <= M; i++) {
            if (nodes[i].empty()) break;
            if (i & 1) {
                reverse(vals[i].begin(), vals[i].end());
                for (int j = 0; j < nodes[i].size(); j++) {
                    nodes[i][j]->val = vals[i][j];
                }
            }
        }
        return root;
    }
};