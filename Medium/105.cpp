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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return NULL;
        int rootVal = preorder[0];
        int idxRoot = -1;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == rootVal) {
                idxRoot = i;
                break;
            }
        }
        TreeNode* ans = new TreeNode(rootVal);
        vector<int> pL(preorder.begin() + 1, preorder.begin() + idxRoot + 1);
        vector<int> iL(inorder.begin(), inorder.begin() + idxRoot);
        vector<int> pR(preorder.begin() + idxRoot + 1, preorder.end());
        vector<int> iR(inorder.begin() + idxRoot + 1, inorder.end());
        ans->left = buildTree(pL, iL);
        ans->right = buildTree(pR, iR);
        return ans;
    }
};