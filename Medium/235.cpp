/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val == q->val) return p;
        if (p->val > q->val) swap(p, q);
        int pp = p->val, qq = q->val;
        while (true) {
            int rr = root->val;
            if (qq < rr) root = root->left;
            else if (pp > rr) root = root->right;
            else return root;
        }
    }
};