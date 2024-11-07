class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        int a = nums[0] + nums[1], b = nums[n - 2] + nums[n - 1], c = nums[0] + nums[n - 1];
        vector<int> ve = {a, b, c};
        int ans = 0;
        for (int i = 0; i < 3; i++) {
            vector<vector<int>> dp(n, vector<int>(n));
            for (int len = 2; len <= n; len++) {
                for (int st = 0; st + len - 1 < n; st++) {
                    if (nums[st] + nums[st + 1] == ve[i]) {
                        dp[st][st + len - 1] = max(dp[st][st + len - 1], (st + 2 < n ? dp[st + 2][st + len - 1] : 0) + 1);
                    }
                    if (nums[st + len - 1] + nums[st + len - 2] == ve[i]) {
                        dp[st][st + len - 1] = max(dp[st][st + len - 1], (st + len - 3 >= 0 ? dp[st][st + len - 3] : 0) + 1);
                    }
                    if (nums[st + len - 1] + nums[st] == ve[i]) {
                        dp[st][st + len - 1] = max(dp[st][st + len - 1], dp[st + 1][st + len - 2] + 1);
                    }
                }
            }
            ans = max(ans, dp[0][n - 1]);
        }
        return ans;
    }
};