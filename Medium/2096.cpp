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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        const int N = 1e5;
        int par[N + 2], L[N + 2], R[N + 2], dep[N + 2];
        memset(par, -1, sizeof(par));
        memset(L, -1, sizeof(L));
        memset(R, -1, sizeof(R));
        memset(dep, 0, sizeof(dep));
        function<void(TreeNode*)> dfs = [&](TreeNode* v) {
            if (v->left) {
                par[v->left->val] = v->val;
                L[v->val] = v->left->val;
                dep[v->left->val] = dep[v->val] + 1;
                dfs(v->left);
            }
            if (v->right) {
                par[v->right->val] = v->val;
                R[v->val] = v->right->val;
                dep[v->right->val] = dep[v->val] + 1;
                dfs(v->right);
            } 
        };
        dfs(root);

        int x = startValue, y = destValue;
        if (dep[x] > dep[y]) swap(x, y);
        while (dep[y] > dep[x]) y = par[y];
        while (x != y) {
            x = par[x], y = par[y];
        }
        int lca = x;
        // cout << lca << '\n';
    
        string ret;
        int cur = startValue;
        while (cur != lca) {
            cur = par[cur];
            ret.push_back('U');
        }
        // cout << cur << '\n';
        string tmp;
        cur = destValue;
        while (cur != lca) {
            if (R[par[cur]] == cur) {
                tmp.push_back('R');
            } else {
                tmp.push_back('L');
            }
            cur = par[cur];
        }
        reverse(tmp.begin(), tmp.end());
        ret += tmp;
        return ret;
    }
};