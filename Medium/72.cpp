class Solution {
public:
    int minDistance(string word1, string word2) {
        int m1 = word1.length(), m2 = word2.length();
        vector<vector<int>>  dp(m1 + 1, vector<int>(m2 + 1));
        for (int i = 1; i <= m1; i++) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= m2; i++) {
            dp[0][i] = i;
        }
        const int MX = 2e9;
        for (int i = 1; i <= m1; i++) {
            for (int j = 1; j <= m2; j++) {
                int tmp = MX;
                if (word1[i - 1] == word2[j - 1]) {
                    tmp = min(tmp, dp[i - 1][j - 1]);
                }
                tmp = min(tmp, 1 + dp[i - 1][j]);
                tmp = min(tmp, 1 + dp[i][j - 1]);
                tmp = min(tmp, 1 + dp[i - 1][j - 1]);
                dp[i][j] = tmp;
            }
        }
        return dp[m1][m2];
    }
};