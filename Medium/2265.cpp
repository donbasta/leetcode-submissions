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
    int averageOfSubtree(TreeNode* root) {
        const auto dfs = [&](const auto& self, TreeNode* v) -> vector<int> {
            vector<int> ret(3);
            if (v == NULL) {
                return ret;
            }
            vector<int> vl = self(self, v->left);
            vector<int> vr = self(self, v->right);
            int countNodes = vl[1] + vr[1] + 1;
            int sumValues = vl[2] + vr[2] + v->val;
            int avg = sumValues / countNodes;
            bool ok = (avg == v->val);
            ret[0] = vl[0] + vr[0] + (ok);
            ret[1] = countNodes;
            ret[2] = sumValues;
            return ret;
        };
        
        return dfs(dfs, root)[0];
    }
};