class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        long long tot = accumulate(nums.begin(), nums.end(), 0ll);
        if (2ll * k > tot) {
            return 0;
        }
        int n = nums.size();
        int dp[n][k];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        if (nums[0] < k) {
            dp[0][nums[0]] = 1;
        }
        const int MOD = 1e9 + 7;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < k; j++) {
                dp[i][j] = (dp[i - 1][j]) % MOD;
                if (j >= nums[i]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - nums[i]]) % MOD;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < k; i++) {
            ans = (ans + dp[n - 1][i]) % MOD;
        }
        const function<int(int, int)> fpow = [&](int a, int b) -> int {
            int ret = 1;
            while (b) {
                if (b & 1) ret = (1ll * ret * a) % MOD;
                a = (1ll * a * a) % MOD;
                b >>= 1;
            }
            return ret;
        };
        int ret = fpow(2, n);
        ret = (ret - 2 * ans) % MOD;
        if (ret < 0) ret += MOD;
        return ret;
    }
};