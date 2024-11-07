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
    int longestUnivaluePath(TreeNode* root) {
        int ret = 0;

        function<int(TreeNode*, int)> dfs = [&](TreeNode* v, int value) -> int {
            if (!v) return 0;
            int le = dfs(v->left, v->val);
            int ri = dfs(v->right, v->val);
            ret = max(ret, le + ri);
            if (value != v->val) return 0;
            return 1 + max(le, ri);
        };

        dfs(root, -1);  
        return ret;
    }
};