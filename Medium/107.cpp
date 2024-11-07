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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) return ret;
        const function<void(TreeNode*, int)> dfs = [&](TreeNode* r, int lvl) {
            if (ret.size() <= lvl) {
                ret.push_back(vector<int>{r->val});
            } else {
                ret[lvl].push_back(r->val);
            }
            if (r->left) dfs(r->left, lvl + 1);
            if (r->right) dfs(r->right, lvl + 1);
        };
        dfs(root, 0);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};