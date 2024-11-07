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
    bool isCompleteTree(TreeNode* root) {
        vector<int> sz(105);
        vector<vector<int>> ve(105);
        const function<int(TreeNode*)> countNode = [&](TreeNode* v) -> int {
            if (!v) return 0;
            return 1 + countNode(v->left) + countNode(v->right);
        };
        int t = countNode(root);

        bool sabi = true;
        const function<void(TreeNode*, int, int)> dfs = [&](TreeNode* v, int depth, int val) -> void {
            if (!v) return;
            if ((1 << (depth)) > t) {
                sabi = false;
                return;
            }
            sz[depth]++;
            ve[depth].push_back(val);
            dfs(v->left, depth + 1, 2 * val);
            dfs(v->right, depth + 1, 2 * val + 1);
        };
        dfs(root, 0, 1);
        if (!sabi) return false;
        int check = 1;
        int done = -1;
        for (int i = 0; i < 105; i++) {
            if (sz[i] != check) {
                done = i;
                break;
            }
            check *= 2;
        }
        for (int i = done + 1; i < 105; i++) {
            if (sz[i] > 0) {
                return false;
            }
        }
        int start = (1 << done);
        for (auto e : ve[done]) {
            if (e != start) return false;
            start++;
        }
        return true;
    }
};