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
    int pathSum(TreeNode* root, int targetSum) {
        int lmaoo = 0;
        const function<unordered_map<long long, int>(TreeNode*)> get = [&](TreeNode* v) -> unordered_map<long long, int> {
            unordered_map<long long, int> ret;
            if (!v) return ret;
            int val = v->val;
            unordered_map<long long, int> le = get(v->left);
            unordered_map<long long, int> ri = get(v->right);
            lmaoo += le[targetSum];
            lmaoo += ri[targetSum];
            for (auto e : le) {
                ret[e.first + val] += e.second;
            }
            for (auto e : ri) {
                ret[e.first + val] += e.second;
            }
            ret[val]++;
            return ret;
        };
        unordered_map<long long, int> bruh = get(root);
        lmaoo += bruh[targetSum];
        return lmaoo;
    }
};