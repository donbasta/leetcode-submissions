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
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }

        function<TreeNode*(TreeNode*)> rec = [&](TreeNode* v) -> TreeNode* {
            TreeNode* last = v;
            if (v->left) {
                TreeNode* p = rec(v->left);                
                TreeNode* tmp = v->right;
                v->right = v->left;
                p->right = tmp;
                last = p;
                v->left = nullptr;
            }
            if (v->right) {
                last = rec(v->right);
            }
            return last;
        };
        rec(root);
    }
};