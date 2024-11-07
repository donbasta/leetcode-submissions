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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root->left && !root->right) return -1;
        int a = root->left->val, b = root->right->val;
        if (a < b) {
            int p = findSecondMinimumValue(root->left);
            if (p == -1) p = INT_MAX;
            return min(p, b);
        } else if (a > b) {
            int q = findSecondMinimumValue(root->right);
            if (q == -1) q = INT_MAX;
            return min(q, a);
        }
        int p = findSecondMinimumValue(root->left);
        int q = findSecondMinimumValue(root->right);
        if (p == -1) p = INT_MAX;
        if (q == -1) q = INT_MAX;
        if (min(p, q) == INT_MAX) return -1;
        return min(p, q);
    }
};