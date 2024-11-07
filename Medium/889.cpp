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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        const function<TreeNode*(int, int, int, int)> construct = [&](int l1, int r1, int l2, int r2) -> TreeNode* {
            assert (r1 - l1 == r2 - l2);
            if (r1 < l1) return nullptr;
            if (r1 == l1) {
                return new TreeNode(preorder[r1]);
            }
            TreeNode* ret = new TreeNode(preorder[l1]);
            int idx = l2;
            while (postorder[idx] != preorder[l1 + 1]) idx++;
            ret->left = construct(l1 + 1, l1 + 1 + idx - l2, l2, idx);
            ret->right = construct(l1 + 2 + idx - l2, r1, idx + 1, r2 - 1);
            return ret;
        };
        int n = preorder.size();
        return construct(0, n - 1, 0, n - 1);
    }
};