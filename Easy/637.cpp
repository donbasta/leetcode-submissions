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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        vector<int> sz;
        const function<void(TreeNode*, int)> dfs = [&](TreeNode* r, int lvl) {
            if (ret.size() <= lvl) {
                ret.push_back(r->val);
                sz.push_back(1);
            } else {
                ret[lvl] += r->val;
                sz[lvl]++;
            }
            if (r->left) dfs(r->left, lvl + 1);
            if (r->right) dfs(r->right, lvl + 1);
        };
        dfs(root, 0);
        for (int i = 0; i < (int)ret.size(); i++) {
            ret[i] /= sz[i];
        }
        return ret;
    }
};