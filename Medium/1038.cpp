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
    TreeNode* bstToGst(TreeNode* root) {
       vector<int> ar;
        const function<void(TreeNode*)> dfs = [&](TreeNode *v) -> void {
            if (!v) return;
            dfs(v->left);
            ar.push_back(v->val);
            dfs(v->right);
        };
        dfs(root);
        int tmp = 0;
        map<int, int> mp;
        for (int i = ar.size() - 1; i >= 0; i--) {
            tmp += ar[i];
            mp[ar[i]] = tmp;
        }
        const function<void(TreeNode*)> dfs2 = [&](TreeNode *v) -> void {
            if (!v) return;
            v->val = mp[v->val];
            dfs2(v->left);
            dfs2(v->right);
        };
        dfs2(root);
        return root;
    }
};