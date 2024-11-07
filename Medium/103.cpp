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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ve(2000);
        const function<void(TreeNode*, int)> dfs = [&](TreeNode* v, int depth) -> void {
            if (v == nullptr) return;
            ve[depth].push_back(v->val);
            dfs(v->left, depth + 1);
            dfs(v->right, depth + 1);
        };
        dfs(root, 0);
        for (int i = 0; i < 2000; i++) {
            if (ve[i].empty()) break;
            if (i & 1) reverse(ve[i].begin(), ve[i].end());
        }
        while (!ve.empty() && ve.back().empty()) {
            ve.pop_back();
        }
        return ve;
    }
};