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
    int getMinimumDifference(TreeNode* root) {
        vector<int> ve;
        const function<void(TreeNode*)> traverseTree = [&](TreeNode* v) -> void {
            if (!v) return;
            traverseTree(v->left);
            ve.push_back(v->val);
            traverseTree(v->right);
        };
        traverseTree(root);
        int n = ve.size();
        int mn = INT_MAX;
        for (int i = 1; i < n; i++) {
            mn = min(mn, ve[i] - ve[i - 1]);
        }
        return mn;
    }
};