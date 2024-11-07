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
    int deepestLeavesSum(TreeNode* root) {
        const auto dfs = [&](const auto& self, TreeNode* v, int depth) -> vector<pair<int, int>> {
            if (v == NULL) {
                return vector<pair<int, int>>{};
            }
            if (v->left == NULL && v->right == NULL) {
                return vector<pair<int, int>>{make_pair(v->val, depth)};
            }
            vector<pair<int, int>> vl = self(self, v->left, depth + 1);
            vector<pair<int, int>> vr = self(self, v->right, depth + 1);
            vl.insert(vl.end(), vr.begin(), vr.end());
            return vl;
        };

        vector<pair<int, int>> A = dfs(dfs, root, 0);
        int mx = 0;
        for (auto e : A) {
            mx = max(mx, e.second);
        }
        int ans = 0;
        for (auto e : A) {
            if (e.second == mx) {
                ans += e.first;
            }
        }
        return ans;
    }
};