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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ret = 0;
        const function<void(TreeNode*)> dfs = [&](TreeNode* v) {
            if (v->val >= low && v->val <= high) {
                ret += v->val;
            }
            if (v->left) dfs(v->left);
            if (v->right) dfs(v->right);
        };
        dfs(root);
        return ret;
    }
};