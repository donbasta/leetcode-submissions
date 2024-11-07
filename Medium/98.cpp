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
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        
        const long long INF = 1e18;

        const function<long long(TreeNode*)> mxBST = [&](TreeNode* root) -> long long {
            if (root == NULL) return -INF;
            long long mxRight = (root->right != NULL ? mxBST(root->right) : -INF);
            long long mxLeft = (root->left != NULL ? mxBST(root->left) : -INF);
            return max({(long long) root->val, mxRight, mxLeft});
        };
        
        const function<long long(TreeNode*)> mnBST = [&](TreeNode* root) -> long long {
            if (root == NULL) return INF;
            long long mnRight = (root->right != NULL ? mnBST(root->right) : INF);
            long long mnLeft = (root->left != NULL ? mnBST(root->left) : INF);
            return min({(long long) root->val, mnRight, mnLeft});
        };

        bool okLeft = mxBST(root->left) < (long long) root->val;
        bool okRight = mnBST(root->right) > (long long) root->val;

        return isValidBST(root->left) && isValidBST(root->right) && okLeft && okRight;
    }
};