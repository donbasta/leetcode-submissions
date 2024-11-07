class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int dp[n][2005];
        memset(dp, 0, sizeof(dp));

        auto tbl = [&](int a, int b) -> int& {
            return dp[a][b + 1000];
        };
        tbl(0, nums[0]) += 1;
        tbl(0, -nums[0]) += 1;
        // dp[i][j] = dp[i - 1][j - nums[i]] + dp[i - 1][j + nums[i]];
        for (int i = 1; i < n; i++) {
            for (int j = -1000; j <= 1000; j++) {
                if (j - nums[i] >= -1000) tbl(i, j) += tbl(i - 1, j - nums[i]);
                if (j + nums[i] <= 1000) tbl(i, j) += tbl(i - 1, j + nums[i]);
            }
        }
        return tbl(n - 1, target);
    }
};