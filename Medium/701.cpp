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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        const function<void(TreeNode*&, int)> dfs = [&](TreeNode*& v, int new_val) {
            if (v->val < new_val) {
                if (v->right) dfs(v->right, new_val);
                else v->right = new TreeNode(new_val);
            } else if (v->val > new_val) {
                if (v->left) dfs(v->left, new_val);
                else v->left = new TreeNode(new_val);
            }
        };
        dfs(root, val);
        return root;
    }
};