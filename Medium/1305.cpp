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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ret;
        const function<void(TreeNode*)> dfs = [&](TreeNode* root) -> void {
            if (!root) return;
            ret.push_back(root->val);
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root1);
        dfs(root2);
        sort(ret.begin(), ret.end());
        return ret;
    }
};