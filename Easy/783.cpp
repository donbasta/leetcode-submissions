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
    int minDiffInBST(TreeNode* root) {
        const int INF = 2e9;
        int ans = INF;
        const function<pair<int, int>(TreeNode*)> lol = [&](TreeNode* v) -> pair<int, int> {
            if (v == nullptr) {
                return make_pair(-INF, INF);
            }
            pair<int, int> ki = lol(v->left);
            pair<int, int> ka = lol(v->right);
            ans = min(ans, v->val - ki.first);
            ans = min(ans, ka.second - v->val);
            return make_pair(max(v->val, ka.first), min(v->val, ki.second));
        };
        lol(root);
        return ans;
    }
};