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
    string smallestFromLeaf(TreeNode* root) {
        string tmp, ret(10000, 'z');
        const function<void(TreeNode*)> dfs = [&](TreeNode* v) {
            tmp.push_back((char)(v->val + 'a'));
            if (!v->right && !v->left) {
                string cp = tmp;
                reverse(cp.begin(), cp.end());
                ret = min(ret, cp);
            }
            if (v->left) dfs(v->left);
            if (v->right) dfs(v->right);
            tmp.pop_back();
        };
        dfs(root);
        return ret;
    }
};