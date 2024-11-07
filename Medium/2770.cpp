class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        int dp[n];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            int tmp = -1;
            for (int j = 0; j < i; j++) {
                if (dp[j] == -1) continue;
                if (abs(nums[i] - nums[j]) <= target) {
                    tmp = max(tmp, 1 + dp[j]);
                }
            }
            dp[i] = tmp;
        }
        return dp[n - 1];
    }
};