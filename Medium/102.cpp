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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        vector<vector<int>> L = levelOrder(root->left);
        vector<vector<int>> R = levelOrder(root->right);
        ans.push_back({root->val});
        int l = L.size(), r = R.size();
        for (int i = 0; i < max(l, r); i++) {
            vector<int> tmp;
            if (i < l) {
                for (auto e : L[i]) tmp.push_back(e);
            }
            if (i < r) {
                for (auto e : R[i]) tmp.push_back(e);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};