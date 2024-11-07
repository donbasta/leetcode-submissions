class Solution {
public:
    int numberOfArrays(string s, int k) {
        const int MOD = 1e9 + 7;
        int n = s.length();
        int dp[n];
        memset(dp, -1, sizeof(dp));
        const function<int(int)> solve = [&](int idx) -> int {
            if (idx >= n) return 1;
            if (dp[idx] != -1) return dp[idx];
            int tmp = 0;
            int j = idx;
            long long cur = 0;
            while (j < n) {
                cur = cur * 10 + s[j] - '0';
                if (cur > 1ll * k) break;
                if ((j + 1 < n && s[j + 1] != '0') || (j + 1 == n)) {
                    tmp = (tmp + solve(j + 1)) % MOD;
                }
                j++;
            }
            return dp[idx] = tmp;
        }; 
        return solve(0);
    }
};