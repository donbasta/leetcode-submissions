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
    vector<int> solve(TreeNode* root) {
        vector<int> ret;
        const function<void(TreeNode*)> dfs = [&](TreeNode* v) {
            if (!v->left && !v->right) {
                ret.push_back(v->val);
                return;
            }
            if (v->left) {
                dfs(v->left);
            }
            if (v->right) {
                dfs(v->right);
            }
        };
        dfs(root);
        return ret;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return solve(root1) == solve(root2);
    }
};