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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        const function<void(TreeNode*)> dfs = [&](TreeNode* v) -> void {
            if (!v) return;
            dfs(v->left);
            dfs(v->right);
            ret.push_back(v->val);
        };
        dfs(root);
        return ret;
    }
};