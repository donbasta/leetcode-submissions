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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ve(200, -200);
        const function<void(TreeNode*, int)> dfs = [&](TreeNode* v, int level) -> void {
            if (v == nullptr) return;
            ve[level] = v->val;
            dfs(v->left, level + 1);
            dfs(v->right, level + 1);
        };
        dfs(root, 0);
        while (!ve.empty() && ve.back() == -200) {
            ve.pop_back();
        }
        return ve;
    }
};