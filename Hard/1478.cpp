class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());
        int n = houses.size();
        // const long long INF = 1e18;
        long long dp[n][k + 1];
        // vector<vector<long long>> dp(n, vector<long long>(k + 1, INF));
        long long pf[n];
        pf[0] = houses[0];
        for (int i = 1; i < n; i++) {
            pf[i] = pf[i - 1] + houses[i];
        }
        const function<long long(int, int)> range_sum = [&](int l, int r) -> long long {
            return pf[r] - (l ? pf[l - 1] : 0);
        };
        const function<long long(int, int)> f = [&](int l, int r) -> long long {
            int cnt = (r - l + 1);
            if (cnt & 1) {
                return range_sum(l + (cnt / 2), r) - range_sum(l, l + (cnt / 2));
            }
            return range_sum(l + (cnt / 2), r) - range_sum(l, l + (cnt / 2) - 1);
        };
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = f(0, i);
            }
            for (int j = 2; j <= k; j++) {
                for (int x = 0; x < i; x++) {
                    dp[i][j] = min(dp[i][j], dp[x][j - 1] + f(x + 1, i));
                }
            }
        }
        return dp[n - 1][k];
    }
};