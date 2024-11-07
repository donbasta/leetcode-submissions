class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        vector<vector<int>> dp(26, vector<int>(26, -1));
        dp[words[0][0] - 'a'][words[0].back() - 'a'] = 0;
        int n = words.size();
        int ret = 0;
        for (int i = 0; i < n; i++) ret += words[i].length();
        for (int i = 1; i < n; i++) {
            vector<vector<int>> ndp(26, vector<int>(26, -1));
            int a = words[i][0] - 'a', b = words[i].back() - 'a';
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    if (dp[j][k] == -1) continue;
                    int x = dp[j][k], y = dp[j][k];
                    if (j == b) x++;
                    if (a == k) y++;
                    ndp[a][k] = max(ndp[a][k], x);
                    ndp[j][b] = max(ndp[j][b], y);
                }
            }
            dp.swap(ndp);
        }
        int buang = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (dp[i][j] == -1) continue;
                buang = max(buang, dp[i][j]);
            }
        }
        return ret - buang;
    }
};