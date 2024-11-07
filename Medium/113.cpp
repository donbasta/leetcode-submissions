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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ret;
        if (root == nullptr) return ret;

        unordered_map<TreeNode*, int> sum;
        unordered_map<TreeNode*, TreeNode*> par;
        const function<void(TreeNode*)> dfs = [&](TreeNode* v) -> void {
            sum[v] += v->val;
            if (v->left) {
                sum[v->left] += sum[v];
                par[v->left] = v;
                dfs(v->left);
            }
            if (v->right) {
                sum[v->right] += sum[v];
                par[v->right] = v;
                dfs(v->right);
            }
        };
        dfs(root);
        for (auto e : sum) {
            if (!e.first->left && !e.first->right && e.second == targetSum) {
                vector<int> tmp;
                TreeNode* cur = e.first;
                while (cur != root) {
                    tmp.push_back(cur->val);
                    cur = par[cur];
                }
                tmp.push_back(cur->val);
                reverse(tmp.begin(), tmp.end());
                ret.push_back(tmp);
            } 
        }
        return ret;
    }
};