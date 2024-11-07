class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        if (n == 1) return 0;
        if (n == 2) return min(stoneValue[0], stoneValue[1]);
        int dp[n][n];
        int pre[n];
        pre[0] = stoneValue[0];
        for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + stoneValue[i];
        auto get = [&](int a, int b) -> int {
            return pre[b] - (a ? pre[a - 1] : 0);
        };
        for (int i = 0; i < n; i++) dp[i][i] = 0;
        for (int i = 0; i < n - 1; i++) dp[i][i + 1] = min(stoneValue[i], stoneValue[i + 1]);
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) { //dp[i][i + len - 1]
                int tmp = 0;
                for (int k = i; k < i + len - 1; k++) {
                    int L = get(i, k), R = get(k + 1, i + len - 1);
                    if (L > R) {
                        tmp = max(tmp, R + dp[k + 1][i + len - 1]);
                    } else if (L < R) {
                        tmp = max(tmp, L + dp[i][k]);
                    } else {
                        tmp = max(tmp, L + max(dp[i][k], dp[k + 1][i + len - 1]));
                    }
                }
                dp[i][i + len - 1] = tmp;
            }
        }
        return dp[0][n - 1];
    }
};