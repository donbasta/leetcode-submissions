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
    bool isEvenOddTree(TreeNode* root) {
        const int M = 1e5;
        vector<int> last(M + 1, -1);
        bool ok = true;
        const function<void(TreeNode*, int)> dfs = [&](TreeNode* v, int dep) {
            if (last[dep] == -1) {
                last[dep] = v->val;
                if ((dep & 1) && (v->val & 1)) ok = false;
                if ((dep % 2 == 0) && (v->val % 2 == 0)) ok = false;
            } else {
                if ((dep & 1) && ((v->val >= last[dep]) || ((v->val) & 1))) ok = false;
                if ((!(dep & 1)) && ((v->val <= last[dep]) || (v->val % 2 == 0))) ok = false;
                last[dep] = v->val;
            }
            if (v->left) dfs(v->left, dep + 1);
            if (v->right) dfs(v->right, dep + 1);
        };
        dfs(root, 0);
        return ok;
    }
};