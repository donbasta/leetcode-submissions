using ll = long long;

class Solution {
public:
    ll maximumStrength(vector<int>& nums, int k) {
        const ll INF = 2e15;
        int n = nums.size();
        ll pre[n];
        for (int i = 0; i < n; i++) pre[i] = 1ll * nums[i] + (i ? pre[i - 1] : 0);

        ll dp[n + 1][k + 1], pd[n + 1][k + 1], ep[n + 1][k + 1], pe[n + 1][k + 1];
        for (int i = 0; i <= n; i++) for (int j = 0; j <= k; j++) {
            dp[i][j] = ep[i][j] = -INF;
            pd[i][j] = pe[i][j] = INF;
        }
        for (int i = 0; i <= n; i++) dp[i][0] = pd[i][0] = ep[i][0] = pe[i][0] = 0;
        dp[n - 1][1] = pd[n - 1][1] = nums[n - 1];
        ep[n - 1][1] = pe[n - 1][1] = pre[n - 1];

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i + 1][j];
                dp[i][j] = max(dp[i][j], ep[i][j] - 1ll * j * (i ? pre[i - 1] : 0));
                pd[i][j] = pd[i + 1][j];
                pd[i][j] = min(pd[i][j], pe[i][j] - 1ll * j * (i ? pre[i - 1] : 0));
            }
            if (i >= 1) {
                for (int j = 1; j <= k; j++) {
                    ep[i - 1][j] = max(ep[i][j], 1ll * j * (i ? pre[i - 1] : 0) - pd[i][j - 1]);
                    pe[i - 1][j] = min(pe[i][j], 1ll * j * (i ? pre[i - 1] : 0) - dp[i][j - 1]);
                }
            } 
        }
        return dp[0][k];
    }
};