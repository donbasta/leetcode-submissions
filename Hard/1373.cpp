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
    int maxSumBST(TreeNode* root) {
        unordered_map<TreeNode*, bool> isBST;
        unordered_map<TreeNode*, int> mx, mn, sum;
        isBST[nullptr] = true;
        const int INF = 2e9;
        mx[nullptr] = -INF;
        mn[nullptr] = INF;
        sum[nullptr] = 0;
        int ans = 0;
        const function<void(TreeNode*)> dfsBST = [&](TreeNode* t) -> void {
            if (t == NULL) return;
            dfsBST(t->left);
            dfsBST(t->right);
            sum[t] = t->val + sum[t->left] + sum[t->right];
            mx[t] = max(max(t->val, mx[t->left]), mx[t->right]);
            mn[t] = min(min(t->val, mn[t->left]), mn[t->right]);
            bool checkRoot = (mx[t->left] < t->val) && (mn[t->right] > t->val);
            isBST[t] = checkRoot && isBST[t->left] && isBST[t->right];
            if (isBST[t]) {
                ans = max(ans, sum[t]);
            }
        };
        dfsBST(root);
        return ans;
    }
};