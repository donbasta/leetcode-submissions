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
    vector<bool> vis;
    vector<vector<TreeNode*>> memo;

    vector<TreeNode*> allPossibleFBT(int n) {
        vis.resize(25);
        memo.resize(25);
        for (int i = 1; i <= n; i++) {
            allPossibleFBTUtil(i);
        }
        return memo[n];
    }

    void allPossibleFBTUtil(int n) {
        if (vis[n]) return;
        if (n == 2) {
            vis[2] = true;
            return;
        }
        if (n == 1) {
            vis[1] = true;
            memo[1] = {new TreeNode()};
            return;
        };

        vector<TreeNode*> tmp;
        for (int i = 1; i < n; i++) {
            for (auto e : memo[i]) {
                for (auto f : memo[n - 1 - i]) {
                    TreeNode* ans = new TreeNode();
                    ans->left = e;
                    ans->right = f;
                    tmp.push_back(ans);
                }
            }
        }
        vis[n] = true;
        memo[n] = tmp;
        return;
    }
};