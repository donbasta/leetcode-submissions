class Solution {
public:
    int minimumDistance(string word) {
        int n = word.size();
        int dp[27][27][n];
        const int INF = 2e9;
        for (int i = 0; i <= 26; i++) for (int j = 0; j <= 26; j++) for (int k = 0; k < n; k++) dp[i][j][k] = INF;

        auto chkmin = [&](int& x, int y) {
            x = min(x, y);
        };

        auto dis = [&](int x, int y) -> int {
            if (x == 26 || y == 26) return 0;
            int px = x / 6, qx = x % 6;
            int py = y / 6, qy = y % 6;
            return abs(px - py) + abs(qx - qy); 
        };

        dp[26][word[0] - 'A'][0] = 0;
        dp[word[0] - 'A'][26][0] = 0;
        for (int i = 1; i < n; i++) {
            int cur = word[i] - 'A';
            for (int j = 0; j <= 26; j++) {
                for (int k = 0; k <= 26; k++) {
                    if (dp[k][j][i - 1] != INF) {
                        chkmin(dp[cur][j][i], dp[k][j][i - 1] + dis(k, cur));
                    }
                    if (dp[j][k][i - 1] != INF) {
                        chkmin(dp[j][cur][i], dp[j][k][i - 1] + dis(k, cur));
                    }
                }                
            }
        }

        // cout << dp[0][26][1] << '\n';
    
        int ans = INF;
        for (int i = 0; i <= 26; i++) {
            for (int j = 0; j <= 26; j++) {
                chkmin(ans, dp[i][j][n - 1]);
            }
        }
        return ans;
    }
};