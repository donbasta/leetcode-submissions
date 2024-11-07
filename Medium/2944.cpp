class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        int dp[n];
        memset(dp, -1, sizeof(dp));
        for (int i = n - 1; i >= 0; i--) {
            int tmp = prices[i];
            if (i + (i + 1) >= n - 1) {
                dp[i] = tmp;
            } else {
                int tam = INT_MAX;
                for (int j = i + 1; j <= min(n - 1, i + (i + 1)); j++) {
                    tam = min(tam, dp[j]);
                }
                tam = min(tam, dp[i + (i + 2)]);
                dp[i] = tmp + tam;
            }
        }
        return dp[0];
    }
};