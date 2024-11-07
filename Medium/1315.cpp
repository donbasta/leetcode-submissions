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
    int sumEvenGrandparent(TreeNode* root) {
        map<TreeNode*, TreeNode*> par;
        const function<void(TreeNode*)> fillPar = [&](TreeNode* v) -> void {
            if (v->left) par[v->left] = v, fillPar(v->left);
            if (v->right) par[v->right] = v, fillPar(v->right);
        };
        fillPar(root);
        const function<int(TreeNode*)> lol = [&](TreeNode* v) -> int {
            int ret = 0;
            if (v->left) ret += lol(v->left);
            if (v->right) ret += lol(v->right);
            if (par[v] != nullptr) {
                if (par[par[v]] != nullptr && (par[par[v]]->val % 2 == 0)) {
                    ret += v->val;
                }
            }
            return ret;
        };
        return lol(root);
    }
};