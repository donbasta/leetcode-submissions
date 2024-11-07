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
    bool isBalanced(TreeNode* root) {
        const function<int(TreeNode*)> height = [&](TreeNode* v) -> int {
            if (!v) return 0;
            return max(height(v->left), height(v->right)) + 1;
        };
        const function<bool(TreeNode*)> check = [&](TreeNode*v) -> bool {
            if (!v) return true;
            bool ret = check(v->left) && check(v->right);
            ret &= abs(height(v->left) - height(v->right)) <= 1;
            return ret;
        };
        return check(root);
    }
};