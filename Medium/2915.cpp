class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        if (nums[0] <= target) dp[0][nums[0]] = 1;
        dp[0][0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= target; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i] && dp[i - 1][j - nums[i]] != -1) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - nums[i]] + 1);
                }
            }
        }
        return dp[n - 1][target];
    }
};