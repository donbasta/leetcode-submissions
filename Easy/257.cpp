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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        vector<int> tmp;
        string arrow = "->";
        const function<string()> conv = [&]() -> string {
            string lmao;
            int n = tmp.size();
            for (int i = 0; i < n; i++) {
                lmao += to_string(tmp[i]);
                if (i < n - 1) lmao += arrow;
            }
            return lmao;
        };
        const function<void(TreeNode*)> dfs = [&](TreeNode* v) {
            tmp.push_back(v->val);
            if (!v->left && !v->right) ret.push_back(conv());
            if (v->left) dfs(v->left);
            if (v->right) dfs(v->right);
            tmp.pop_back();
        };
        dfs(root);
        return ret;
    }
};