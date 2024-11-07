class Solution {
public:
    int sumOfPower(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<vector<int>> dp(k + 1, vector<int>(n + 1));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            vector<vector<int>> pd = dp;
            for (int sum = nums[i]; sum <= k; sum++) {
                for (int cnt = 1; cnt <= n; cnt++) {
                    pd[sum][cnt] = (pd[sum][cnt] + dp[sum - nums[i]][cnt - 1]) % MOD;
                }
            }
            dp.swap(pd);
        }
        int ans = 0, pw = 1;
        for (int i = n; i >= 0; i--) {
            int tmp = (1ll * dp[k][i] * pw) % MOD;
            pw = (pw * 2) % MOD;
            ans = (ans + tmp) % MOD;
        }
        return ans;
    }
};