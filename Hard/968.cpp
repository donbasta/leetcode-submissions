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
    map<TreeNode*, vector<int>> mp;
    const int INF = 1e9;
    void dfs(TreeNode* v) {
        mp[v].resize(3);
        int a, b = 0, c = 0;
        if (v->left) {
            dfs(v->left);
            b += min({mp[v->left][0], mp[v->left][1], mp[v->left][2]});
            c += mp[v->left][0];
        }
        if (v->right) {
            dfs(v->right);
            b += min({mp[v->right][0], mp[v->right][1], mp[v->right][2]});
            c += mp[v->right][0];
        }
        if (v->left && v->right) {
            a = min({mp[v->left][0] + mp[v->right][1], mp[v->left][1] + mp[v->right][0], mp[v->left][1] + mp[v->right][1]});
        } else if (v->left) {
            a = mp[v->left][1];
        } else if (v->right) {
            a = mp[v->right][1];
        } else {
            a = INF;
        }
        b++;
        mp[v][0] = a, mp[v][1] = b, mp[v][2] = c;
    }
    int minCameraCover(TreeNode* root) {
        dfs(root);
        return min(mp[root][0], mp[root][1]);
    }
};