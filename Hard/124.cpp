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
    int maxPathSum(TreeNode* root) {
        const function<int(TreeNode*)> maxPathSumContainingRoot = [&](TreeNode* v) -> int {
            if (v == NULL) return 0;
            return (v->val) + max({0, maxPathSumContainingRoot(v->right), maxPathSumContainingRoot(v->left)});
        };
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return root->val;
        int a = maxPathSumContainingRoot(root->left);
        int b = maxPathSumContainingRoot(root->right);
        int al = maxPathSum(root->left);
        int bl = maxPathSum(root->right);
        if (root->left == NULL) {
            return max(root->val + max(0, b), bl);
        }
        if (root->right == NULL) {
            return max(root->val + max(0, a), al);
        }
        return max({
            al, bl,
            max(0, a) + max(0, b) + root->val
        });
    }
};