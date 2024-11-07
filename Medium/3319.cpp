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
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> ve;
        map<TreeNode*, int> sz;
        map<TreeNode*, bool> ok;
        function<void(TreeNode*)> dfs = [&](TreeNode* v) {
            sz[v] = 1;
            if ((!v->left) && (!v->right)) {
                ok[v] = true;
                ve.push_back(1);
                return;
            }
            if (v->left) { dfs(v->left); sz[v] += sz[v->left]; }
            if (v->right) { dfs(v->right); sz[v] += sz[v->right]; }
            if (ok[v->left] && ok[v->right] && (sz[v->left] == sz[v->right])) {
                ok[v] = true;
                ve.push_back(sz[v]);
            }
        };
        dfs(root);
        sort(ve.begin(), ve.end());
        reverse(ve.begin(), ve.end());
        // for (auto e : ve) {
        //     cout << e << ' ';
        // }
        // cout << '\n';
        if ((int)ve.size() < k) return -1;
        return ve[k - 1];
    }
};