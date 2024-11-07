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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* tmp = new TreeNode(val);
        if (val > root->val) {
            tmp->left = root;
            return tmp;
        }

        TreeNode* prv = root;
        TreeNode* cur = root->right;
        if (cur == nullptr) {
            root->right = tmp;
            return root;
        }
        while (true) {
            if (cur->val < val) {
                prv->right = tmp;
                tmp->left = cur;
                return root;
            } else {
                if (!cur->right) {
                    cur->right = tmp;
                    return root;
                }
                prv = cur;
                cur = cur->right;
            }
        }
        assert(false);
        return nullptr;
    }
};