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
    bool isEqual(TreeNode* a, TreeNode* b) {
        if (a == nullptr) return a == b;
        if (b == nullptr) return a == b;
        return (a->val == b->val) && isEqual(a->left, b->left) && isEqual(a->right, b->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) return root == subRoot;
        if (subRoot == nullptr) return true; 
        bool hehe = isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        bool bruh = false;
        if (root->val == subRoot->val) {
            bruh = isEqual(root->left, subRoot->left) && isEqual(root->right, subRoot->right);
        }
        return hehe || bruh;
    }
};