class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.length();
        const int INF = 2e9;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                int tmp = INF;
                for (int l = 0; l < i; l++) {
                    if (dp[l][j - 1] == INF) continue;
                    // min change so l+1 .. i jd palindrome
                    int changes = 0;
                    for (int u = l; u <= (i + l - 2) / 2; u++) {
                        changes += (s[u] != s[i + l - 1 - u]);
                    }
                    tmp = min(tmp, changes + dp[l][j - 1]);
                }
                dp[i][j] = tmp;
            }
        }
        return dp[n][k];
    }
};