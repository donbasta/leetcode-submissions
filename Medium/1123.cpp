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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int count[1001], depth[1001];
        memset(depth, -1, sizeof(depth));

        function<void(TreeNode*)> dfs = [&](TreeNode* v) {
            int mx_depth = 1;
            int cnt = 0;
            if (v->left) {
                dfs(v->left);
                mx_depth = max(mx_depth, depth[v->left->val] + 1);
            }
            if (v->right) {
                dfs(v->right);
                mx_depth = max(mx_depth, depth[v->right->val] + 1);
            }

            if (v->left) {
                if (mx_depth == depth[v->left->val] + 1) cnt += count[v->left->val];
            }
            if (v->right) {
                if (mx_depth == depth[v->right->val] + 1) cnt += count[v->right->val];
            }

            count[v->val] = (mx_depth == 1 ? 1 : cnt);
            depth[v->val] = mx_depth;
        };

        dfs(root);

        TreeNode* cur = root;
        while (true) {
            int now = cur->val;
            bool le = false, ri = false;
            if (cur->left) {
                if (depth[cur->left->val] + 1 == depth[cur->val]) {
                    le = true;
                }
            }
            if (cur->right) {
                if (depth[cur->right->val] + 1 == depth[cur->val]) {
                    ri = true;
                }
            }
            if (le && ri) break;
            else if (le) cur = cur->left;
            else if (ri) cur = cur->right;
            else break;
        }
        return cur;
    }
};