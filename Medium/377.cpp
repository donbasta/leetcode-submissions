class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        // dp[sum][suku] = dp[sum - a[1]][suku-1] + .. + dp[sum - a[n]][suku - 1]

        vector<vector<long long>> dp(target + 1, vector<long long>(target + 1));
        for (int i = 0; i < n; i++) {
            if (nums[i] <= target) dp[nums[i]][1] = 1;
        }
        const int MOD = 1e18;
        for (int i = 2; i <= target; i++) {
            for (int sum = 0; sum <= target; sum++) {
                for (int idx = 0; idx < n; idx++) {
                    if (sum < nums[idx]) continue;
                    dp[sum][i] = (dp[sum][i] + dp[sum - nums[idx]][i - 1]) % MOD;
                }
            }
        } 
        long long ans = 0;
        for (int i = 1; i <= target; i++) {
            ans += dp[target][i];
        }
        return (int) ans;
    }
};