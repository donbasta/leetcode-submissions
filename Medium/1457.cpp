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
    int pseudoPalindromicPaths (TreeNode* root) {
        int ret = 0;
        const function<void(TreeNode*, set<int>&)> dfs = [&](TreeNode* v, set<int>& s) {
            if (!v->left && !v->right) {
                ret += ((int)s.size() <= 1);
                return;
            }
            if (v->left) {
                if (s.count(v->left->val)) s.erase(v->left->val);
                else s.insert(v->left->val);
                dfs(v->left, s);
                if (s.count(v->left->val)) s.erase(v->left->val);
                else s.insert(v->left->val);
            }
            if (v->right) {
                if (s.count(v->right->val)) s.erase(v->right->val);
                else s.insert(v->right->val);
                dfs(v->right, s);
                if (s.count(v->right->val)) s.erase(v->right->val);
                else s.insert(v->right->val);
            }
        };
        set<int> se;
        se.insert(root->val);
        dfs(root, se);
        return ret;
    }
};