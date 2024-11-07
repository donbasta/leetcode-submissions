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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodeVals;
        const function<void(TreeNode*)> dfs = [&](TreeNode* v) -> void {
            if (!v) return;
            nodeVals.push_back(v->val);
            dfs(v->left);
            dfs(v->right);
        };
        dfs(root);
        int n = nodeVals.size();
        sort(nodeVals.begin(), nodeVals.end());
        const function<TreeNode*(int, int)> build = [&](int l, int r) -> TreeNode* {
            if (l > r) return nullptr;
            if (l == r) return new TreeNode(nodeVals[l]);
            int mid = (l + r) >> 1;
            TreeNode* ret = new TreeNode(nodeVals[mid]);
            ret->left = build(l, mid - 1);
            ret->right = build(mid + 1, r);
            return ret;
        };
        return build(0, n - 1);
    }
};