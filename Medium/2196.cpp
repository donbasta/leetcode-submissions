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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, vector<int>> mp;
        set<int> childrens, nodes;
        for (auto d : descriptions) {
            if (!mp.count(d[0])) {
                mp[d[0]].resize(2);
            }
            mp[d[0]][1 - d[2]] = d[1];
            childrens.insert(d[1]);
            nodes.insert(d[0]);
            nodes.insert(d[1]);
        }
        int root = -1;
        for (auto n : nodes) {
            if (!childrens.count(n)) {
                root = n;
                break;
            }
        }
        assert (root != -1);

        TreeNode* ret = new TreeNode(root);
        function<void(TreeNode*)> dfs = [&](TreeNode* v) {
            if (mp.count(v->val) && mp[v->val][0] != 0) {
                v->left = new TreeNode(mp[v->val][0]);
                dfs(v->left);
            }
            if (mp.count(v->val) && mp[v->val][1]) {
                v->right = new TreeNode(mp[v->val][1]);
                dfs(v->right);
            }
        };
        dfs(ret);
        return ret;
    }
};