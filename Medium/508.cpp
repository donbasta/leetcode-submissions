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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ret;
        unordered_map<int, int> cnt;
        const function<int(TreeNode*)> dfs = [&](TreeNode* v) -> int {
            int sum = v->val;
            if (v->right) sum += dfs(v->right);
            if (v->left) sum += dfs(v->left);
            cnt[sum]++;
            return sum;
        };
        dfs(root);
        int mx = 0;
        for (auto e : cnt) mx = max(mx, e.second);
        for (auto e : cnt) if (e.second == mx) ret.push_back(e.first);
        return ret;
    }
};