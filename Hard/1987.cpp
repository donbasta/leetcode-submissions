class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int n = binary.size();
        int dp[n], last[2], le[n];
        last[0] = last[1] = -1;
        const int MOD = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            le[i] = last[binary[i] - '0'];
            last[binary[i] - '0'] = i;
        }
        dp[0] = 2 - (binary[0] == '0');
        for (int i = 1; i < n; i++) {
            dp[i] = (dp[i - 1] * 2) % MOD;
            if (binary[i] == '0') dp[i]--;
            if (le[i] >= 0) {
                int prv = (le[i] == 0 ? 1 : dp[le[i] - 1]);
                if (binary[i] == '0') prv--;
                dp[i] -= prv;
                if (dp[i] < 0) dp[i] += MOD;
            }
        }
        int ans = dp[n - 1] - 1;
        if (last[0] != -1) ans++;
        ans %= MOD;
        if (ans < 0) ans += MOD;
        return ans;
    }
};