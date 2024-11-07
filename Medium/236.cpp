/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        const int INF = 2e9;
        int mn = INF;
        TreeNode* ret;
        int enter = 0;
        bool startCompare = false;
        bool done_p = false, done_q = false;
        const function<void(TreeNode*, int)> dfsTour = [&](TreeNode* v, int height) -> void {
            if (done_p && done_q) return;
            if (v == p || v == q) {
                startCompare = true;
            }
            if (startCompare && (height < mn)) {
                // cout << v->val << ' ' << height << '\n';
                mn = height, ret = v;
            }
            if (v->left) {
                dfsTour(v->left, height + 1);
                if (!(done_p && done_q) && startCompare && (height < mn)) {
                    // cout << "dari left " << v->val << ' ' << height << '\n';
                    mn = height, ret = v;
                }
            }
            if (v->right) {
                dfsTour(v->right, height + 1);
                if (!(done_p && done_q) && startCompare && (height < mn)) {
                    // cout << "dari right " << v->val << ' ' << height << '\n';
                    mn = height, ret = v;
                }
            }
            if (v == p) done_p = true;
            if (v == q) done_q = true;
        };
        dfsTour(root, 0);
        return ret;
    }
};