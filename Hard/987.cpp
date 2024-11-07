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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<pair<int, int>, vector<int>> mp;
        map<int, vector<int>> mp2;
        const function<void(TreeNode*, int, int)> traverse = [&](TreeNode* x, int r, int c) -> void {
            if (!x) return;
            mp[make_pair(r, c)].push_back(x->val);
            traverse(x->left, r + 1, c - 1);
            traverse(x->right, r + 1, c + 1);
        };
        traverse(root, 0, 0);
        for (auto e : mp) {
            sort(e.second.begin(), e.second.end());
            for (auto ee : e.second) {
                mp2[e.first.second].push_back(ee);
            }
        }
        vector<vector<int>> ret;
        for (auto e : mp2) {
            ret.push_back(e.second);
        }
        return ret;
    }
};