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
    int countPairs(TreeNode* root, int distance) {
        map<TreeNode*, map<int, int>> mp;
        int ret = 0;
        function<void(TreeNode*)> dfs = [&](TreeNode* v) {
            if (v->left) {
                dfs(v->left);
                for (auto e : mp[v->left]) {
                    mp[v][e.first + 1] += e.second;
                }
            }
            if (v->right) {
                dfs(v->right);
                for (auto e : mp[v->right]) {
                    mp[v][e.first + 1] += e.second;
                }
            }
            if ((!v->left) && (!v->right)) {
                mp[v][0] = 1;
            }
            if ((v->left) && (v->right)) {
                for (int a = 1; a <= distance - 1; a++) {
                    for (int b = 1; b <= distance - a; b++) {
                        ret += mp[v->left][a - 1] * mp[v->right][b - 1];
                    }
                }
            }
        };
        dfs(root);
        return ret;
    }
};