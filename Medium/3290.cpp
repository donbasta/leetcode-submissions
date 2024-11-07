class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        using ll = long long;
        ll INF = 2e18;
        ll DP[n][5];
        memset(DP, 0, sizeof(DP));
        DP[0][1] = 1ll * a[0] * b[0];
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= min(4, i + 1); j++) {
                ll val = -INF;
                if (i >= j) val = max(val, DP[i - 1][j]);
                val = max(val, DP[i - 1][j - 1] + 1ll * a[j - 1] * b[i]);
                DP[i][j] = val;
            }
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j <= 4; j++) {
        //         cout << i << ' ' << j << ' ' << DP[i][j] << '\n'; 
        //     }
        // }
        return DP[n - 1][4];
    }
};