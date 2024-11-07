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
    int getMax(TreeNode* root) {
        if (root->right) return getMax(root->right);
        return root->val;
    }
    int getMin(TreeNode* root) {
        if (root->left) return getMin(root->left);
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left) {
                root->val = getMax(root->left);
                root->left = deleteNode(root->left, root->val);
            } else if (root->right) {
                root->val = getMin(root->right);
                root->right = deleteNode(root->right, root->val);
            } else{
                root = nullptr;
            }
        }
        return root;
    }
};