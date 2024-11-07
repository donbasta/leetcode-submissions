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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ret;
        bool cant = false;

        function<int(TreeNode*, int)> dfs = [&](TreeNode* v, int cur_idx) -> int {
            if (voyage[cur_idx] != v->val) {
                cant = true;
            }
            if (!v->left && !v->right) {
                return 1;
            } else if (!v->left) {
                int sz = dfs(v->right, cur_idx + 1);
                return 1 + sz;
            } else if (!v->right) {
                int sz = dfs(v->left, cur_idx + 1);
                return 1 + sz;
            } else {
                if (voyage[cur_idx + 1] != v->left->val) {
                    ret.push_back(v->val);
                    int sz1 = dfs(v->right, cur_idx + 1);
                    int sz2 = dfs(v->left, cur_idx + 1 + sz1);
                    return 1 + sz1 + sz2;
                } else {
                    int sz1 = dfs(v->left, cur_idx + 1);
                    int sz2 = dfs(v->right, cur_idx + 1 + sz1);
                    return 1 + sz1 + sz2;
                }
            }
        };
        dfs(root, 0);

        if (cant) {
            return vector<int>{-1};
        }

        return ret;
    }
};