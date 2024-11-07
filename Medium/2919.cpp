class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2));
        dp[0][1] = max(0, k - nums[0]);
        dp[1][1] = max(0, k - nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 2][1]);
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + max(0, k - nums[i]);
        }
        return min(dp[n - 1][0], dp[n - 1][1]);
    }
};