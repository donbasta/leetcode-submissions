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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        const function<TreeNode*(int, int, int, int)> rec = [&](int l1, int r1, int l2, int r2) -> TreeNode* {
            assert(r1 - l1 == r2 - l2);
            if (r1 < l1) return nullptr;
            int curVal = postorder[r2];
            TreeNode* ret = new TreeNode(curVal);
            if (r2 - l2 + 1 == 1) return ret;
            int split = -1;
            for (int i = l1; i <= r1; i++) {
                if (inorder[i] == curVal) {
                    split = i;
                    break;
                }
            }
            ret->left = rec(l1, split - 1, l2, l2 + split - 1 - l1);
            ret->right = rec(split + 1, r1, l2 + split - l1, r2 - 1);
            return ret;
        };

        return rec(0, n - 1, 0, n - 1);
    }
};