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
    TreeNode* increasingBST(TreeNode* root) {

        function<vector<TreeNode*>(TreeNode*)> dfs = [&](TreeNode* v) -> vector<TreeNode*> {
            TreeNode* head = nullptr;
            TreeNode* tail = nullptr;
            TreeNode* cur = nullptr;

            if (v->left) {
                vector<TreeNode*> dfs_l = dfs(v->left);
                head = dfs_l[0];
                tail = dfs_l[1];
                tail->right = new TreeNode(v->val);
                cur = tail->right;
                tail = cur;
            } else {
                head = new TreeNode(v->val);
                cur = head;
                tail = head;
            }

            if (v->right) {
                vector<TreeNode*> dfs_r = dfs(v->right);
                tail->right = dfs_r[0];
                tail = dfs_r[1];
            }

            return vector<TreeNode*>{head, tail};
        };

        return dfs(root)[0];
    }
};