class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans = {0};
        for (int i = 1; i <= n; i++) {
            int dp = ans[i / 2] + (i & 1);
            ans.push_back(dp);
        }
        return ans;
    }
};