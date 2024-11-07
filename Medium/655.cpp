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
    vector<vector<string>> printTree(TreeNode* root) {
        int h = -1;
        function<void(TreeNode*, int)> dfs_height = [&](TreeNode* v, int dep) {
            h = max(h, dep);
            if (v->left) dfs_height(v->left, dep + 1);
            if (v->right) dfs_height(v->right, dep + 1);
        };
        dfs_height(root, 1);
        vector<vector<string>> ret(h, vector<string>((1 << h) - 1));

        function<void(TreeNode*, int, int, int)> dfs = [&](TreeNode* v, int dep, int s, int e) {
            int mid = (s + e) >> 1;
            ret[dep][mid] = to_string(v->val);
            if (v->left) dfs(v->left, dep + 1, s, mid - 1);
            if (v->right) dfs(v->right, dep + 1, mid + 1, e);
        };
        dfs(root, 0, 0, (1 << h) - 2);

        return ret;
    }
};