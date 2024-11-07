class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const long long INF = 1e15;
        vector<vector<long long>> dp(26, vector<long long>(26, INF));
        int n = cost.size();
        for (int i = 0; i < 26; i++) {
            dp[i][i] = 0;
        }
        for (int i = 0; i < n; i++) {
            int u = original[i] - 'a', v = changed[i] - 'a';
            dp[u][v] = min(dp[u][v], 1ll * cost[i]);
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    dp[j][k] = min(dp[j][i] + dp[i][k], dp[j][k]);
                }
            }
        }
        int nn = source.length();
        long long ans = 0;
        for (int i = 0; i < nn; i++) {
            int u = source[i] - 'a', v = target[i] - 'a';
            if (dp[u][v] == INF) {
                return -1;
            }
            ans += dp[u][v];
        }
        return ans;
    }
};