class Solution {
public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
        const int M = 2e4;
        const int MOD = 1e9 + 7;
        const int B = 200;

        int n = nums.size();
        int cnt[M + 1], pre[M + 1];
        int dp[r + 1];
        memset(pre, 0, sizeof(pre));
        memset(cnt, 0, sizeof(cnt));
        memset(dp, 0, sizeof(dp));
        for (auto e : nums) cnt[e]++;

        dp[0] = 1;
        for (int i = 0; i <= r; i++) pre[i] = 1;
        for (int i = 1; i <= M; i++) {
            if (cnt[i] == 0) {
                if (i + 1 <= B) {
                    for (int j = 0; j <= r; j++) {
                        if (j < i + 1) pre[j] = dp[j];
                        else {
                            pre[j] = dp[j] + pre[j - (i + 1)];
                            if (pre[j] >= MOD) pre[j] -= MOD;
                        }
                    }
                }
                continue;
            }
            for (int j = r; j >= 1; j--) {
                if (i <= B) {
                    dp[j] = pre[j];
                    if (j >= i * (cnt[i] + 1)) dp[j] -= pre[j - i * (cnt[i] + 1)];
                    if (dp[j] < 0) dp[j] += MOD;
                } else {
                    int tmp = 0;
                    for (int k = j; k >= max(0, j - i * cnt[i]); k -= i) {
                        tmp = (tmp + dp[k]);
                        if (tmp >= MOD) tmp -= MOD;
                    }
                    dp[j] = tmp;
                }
            }
            if (i + 1 <= B) {
                for (int j = 0; j <= r; j++) {
                    if (j < i + 1) pre[j] = dp[j];
                    else {
                        pre[j] = dp[j] + pre[j - (i + 1)];
                        if (pre[j] >= MOD) pre[j] -= MOD;
                    }
                }
            }
        }
        
        int ans = 0;
        for (int i = l; i <= r; i++) {
            ans = (ans + dp[i]) % MOD;
        }
        ans = (1ll * ans * (cnt[0] + 1)) % MOD;
        if (ans < 0) ans += MOD;
        return ans;
    }
};