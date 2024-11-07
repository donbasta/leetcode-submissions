class Solution {
public:
    int minimumChanges(string s, int k) {
        const int M = 200;
        const int INF = 2e9;
        
        int n = s.length();
        vector<int> div[M + 1];
        for (int i = 1; i <= M; i++) {
            for (int j = i; j <= M; j += i) {
                div[j].push_back(i);
            }
        }
        int dp[n][k + 1]; //0-based index, num partition
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = INF;
            }
        }
        
        auto cost = [&](int l, int r) -> int {
            int len = r - l + 1;
            int ans = INF;
            for (auto d : div[len]) {
                if (d == len) continue;
                int part = len / d;
                int tmp = 0;
                for (int i = 0; i < d; i++) {
                    for (int j = 0; j < part / 2; j++) {
                        tmp += (s[j * d + i + l] != s[(part - 1 - j) * d + i + l]);
                    }
                }
                ans = min(ans, tmp);
            }
            return ans;
        };
        
        dp[1][1] = (s[0] != s[1]);
        for (int i = 2; i < n; i++) {
            dp[i][1] = cost(0, i);
            for (int j = 2; j <= k; j++) {
                for (int t = i - 2; t >= 0; t--) {
                    if (dp[t][j - 1] == INF) continue;
                    dp[i][j] = min(dp[i][j], dp[t][j - 1] + cost(t + 1, i));
                }
            }
        }
        return dp[n - 1][k];
    }
};