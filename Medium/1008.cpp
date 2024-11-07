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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }
        int head = preorder[0];
        TreeNode* ans = new TreeNode(head);
        vector<int> left, right;
        for (int i = 1; i < (int) preorder.size(); i++) {
            if (preorder[i] < head) left.push_back(preorder[i]);
            else right.push_back(preorder[i]);
        }
        ans->left = bstFromPreorder(left);
        ans->right = bstFromPreorder(right);
        return ans;
    }
};