class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        if (n <= 2) return true;
        int pre[n], dp[n][n];
        pre[0] = piles[0];
        for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + piles[i];
        auto sum = [&](int l, int r) -> int {
            return pre[r] - (l ? pre[l - 1] : 0);
        };
        for (int i = 0; i < n; i++) dp[i][i] = piles[i];
        for (int i = 0; i < n - 1; i++) dp[i][i + 1] = max(piles[i], piles[i + 1]);
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) { //dp[i][i + len - 1]
                dp[i][i + len - 1] = max(piles[i] + (sum(i + 1, i + len - 1) - dp[i + 1][i + len - 1]), piles[i + len - 1] + (sum(i, i + len - 2) - dp[i][i + len - 2]));
            }
        }
        int tot = pre[n - 1];
        return (dp[0][n - 1] * 2 > tot);
    }
};