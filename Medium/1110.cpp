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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ret;
        bool hps[1001];
        memset(hps, false, sizeof(hps));
        for (auto t : to_delete) hps[t] = true;
        function<void(TreeNode*, TreeNode*, int)> dfs = [&](TreeNode* v, TreeNode* par, int dir) {
            if (hps[v->val]) {
                if (par) {
                    if (dir == 0) par->left = nullptr;
                    else if (dir == 1) par->right = nullptr;
                }
            } else {
                if ((par == nullptr) || (par != nullptr && hps[par->val])) {
                    ret.push_back(v);
                }
            }
            if (v->left) dfs(v->left, v, 0);
            if (v->right) dfs(v->right, v, 1);
        };
        dfs(root, nullptr, -1);
        return ret;
    }
};