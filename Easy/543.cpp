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
    int diameterOfBinaryTree(TreeNode* root) {
        const function<int(TreeNode*)> maxDepth = [&](TreeNode* v) -> int {
            if (!v) return 0;
            return 1 + max(maxDepth(v->left), maxDepth(v->right));
        };
        const function<int(TreeNode*)> diam = [&](TreeNode* v) -> int {
            if (!v) return 0;
            int ret = max(1 + maxDepth(v->left) + maxDepth(v->right), diam(v->left));
            ret = max(ret, diam(v->right));
            return ret;
        };
        return diam(root) - 1;
    }
};