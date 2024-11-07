class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int m = source.length();
        int n = pattern.length();
        int dp[m][n], cnt[m];
        memset(dp, -1, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));

        bool target[m];
        memset(target, false, sizeof(target));

        for (auto t : targetIndices) target[t] = true;
        for (int i = 0; i < m; i++) {
            cnt[i] = (i ? cnt[i - 1] : 0) + target[i];
        }
    
        for (int i = 0; i < m; i++) {
            if (i == 0) {
                if (source[0] == pattern[0]) dp[0][0] = 0;
            } else {
                for (int j = 0; j < n; j++) {
                    if (dp[i - 1][j] != -1) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j] + (target[i]));
                    }
                    if (source[i] == pattern[j]) {
                        if (j >= 1 && dp[i - 1][j - 1] != -1) {
                            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
                        } else if (j == 0) {
                            dp[i][j] = max(dp[i][j], cnt[i - 1]);
                        }
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};