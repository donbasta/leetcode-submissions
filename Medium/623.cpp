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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* ret = new TreeNode(val);
            ret->left = root;
            return ret;
        }
        const function<void(TreeNode*, int)> dfs = [&](TreeNode* v, int cur_dep) {
            if (cur_dep == depth - 1) {
                TreeNode* new_l = new TreeNode(val);
                TreeNode* new_r = new TreeNode(val);
                new_l->left = v->left;
                new_r->right = v->right;
                v->left = new_l;
                v->right = new_r;
                return;
            }
            if (v->left) dfs(v->left, cur_dep + 1);
            if (v->right) dfs(v->right, cur_dep + 1);
        };
        dfs(root, 1);
        return root;
    }
};