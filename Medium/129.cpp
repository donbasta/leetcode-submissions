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
    int sumNumbers(TreeNode* root) {
        long long ans = 0;
        vector<long long> pw(12);
        pw[0] = 1;
        for (int i = 1; i < 12; i++) {
            pw[i] = pw[i - 1] * 10;
        }
        const function<vector<int>(TreeNode*, int)> dfs = [&](TreeNode* v, int depth) -> vector<int> {
            vector<int> cnt(12);
            if (!v) return cnt;

            vector<int> le = dfs(v->left, depth + 1);
            vector<int> ri = dfs(v->right, depth + 1);
            if (accumulate(le.begin(), le.end(), 0) == 0 && accumulate(ri.begin(), ri.end(), 0) == 0) cnt[depth]++;
            for (int i = 0; i < 12; i++) {
                cnt[i] += le[i];
                cnt[i] += ri[i];
            }
            
            for (int i = 0; i < 12; i++) {
                if (i < depth) continue;
                ans += (v->val) * cnt[i] * pw[i - depth];
            }
            return cnt; 
        };
        dfs(root, 0);
        return ans;
    }
};