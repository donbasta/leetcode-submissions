class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int n = word.size();
        int dp[n][26];
        for (int i = 0; i < 26; i++) dp[0][i] = 1;
        dp[0][word[0] - 'a'] = 0;
        for (int i = 1; i < n; i++) {
            int cur = word[i] - 'a';
            for (int j = 0; j < 26; j++) {
                dp[i][j] = INT_MAX;
                for (int k = 0; k < 26; k++) {
                    if (abs(k - j) <= 1) continue;
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + (j != cur));
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < 26; i++) {
            ans = min(ans, dp[n - 1][i]);
        }
        return ans;
    }
};