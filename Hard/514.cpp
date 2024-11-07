class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.length();
        int m = key.length();

        auto step = [&](int a, int b) -> int {
            if (a > b) swap(a, b);
            return min(b - a, n - (b - a));
        };
        
        const int INF = 1e9;
        int dp[n][m];
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) dp[i][j] = INF;
        for (int i = 0; i < n; i++) {
            if (ring[i] == key[0]) {
                dp[i][0] = step(0, i);
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (ring[j] != key[i]) continue;
                for (int k = 0; k < n; k++) {
                    if (ring[k] != key[i - 1]) continue;
                    dp[j][i] = min(dp[j][i], dp[k][i - 1] + step(k, j)); 
                }
            }
        }
        int ans = INF;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[i][m - 1]);
        }
        assert (ans != INF);
        return ans + m;
    }
};