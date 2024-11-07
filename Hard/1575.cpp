class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        const int MOD = 1e9 + 7;
        const int INF = 1e9;
        int n = locations.size();
        int dp[n][fuel + 1];
        memset(dp, 0, sizeof(dp));
        dp[start][0] = 1;
        for (int f = 1; f <= fuel; f++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    int dis = abs(locations[i] - locations[j]);
                    if (f < dis) continue;
                    dp[i][f] = (dp[i][f] + dp[j][f - dis]) % MOD;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= fuel; i++) {
            ans = (ans + dp[finish][i]) % MOD;
        }
        return ans;
    }
};