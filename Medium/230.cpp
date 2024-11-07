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
    int sizeTree(TreeNode* root) {
        if (!root) return 0;
        return 1 + sizeTree(root->left) + sizeTree(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {        
        int leftSize = sizeTree(root->left);
        if (leftSize >= k) {
            return kthSmallest(root->left, k);
        } else if (leftSize == k - 1) {
            return root->val;
        } else {
            return kthSmallest(root->right, k - 1 - leftSize);
        }
    }
};