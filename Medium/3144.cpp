class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.length();
        
        vector<vector<bool>> isb(n, vector<bool>(n));
        vector<int> dp(n, n + 1);
        
        for (int i = 0; i < n; i++) {
            vector<int> tmp(26);
            for (int j = i; j < n; j++) {
                int cur = s[j] - 'a';
                tmp[cur]++;
                int mx = -1, mn = n + 1;
                for (int k = 0; k < 26; k++) {
                    if (tmp[k] == 0) continue;
                    mx = max(mx, tmp[k]);
                    mn = min(mn, tmp[k]);
                }
                if (mx == mn) isb[i][j] = true;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (isb[0][i]) dp[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (isb[j + 1][i]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        
        return dp[n - 1];
    }
};