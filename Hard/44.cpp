class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.length();
        int np = p.length();

        // dp[i][j]
        // --> if (p[j - 1] char)
        // ----> dp[i][j] = dp[i - 1][j - 1] & s[i - 1] == p[j - 1]
        // --> if (p[j - 1] == '?') 
        // ----> dp[i][j] = dp[i - 1][j - 1]
        // --> if (p[j - 1] == '*') 
        // ----> dp[i][j] = dp[i][j - 1] | dp[i - 1][j - 1] | ... | dp[0][j - 1] = ndp[i][j - 1]

        vector<vector<bool>> dp(ns + 1, vector<bool>(np + 1));
        vector<vector<bool>> ndp(ns + 1, vector<bool>(np + 1));

        for (int i = 0; i <= np; i++) {
            if (i && (p[i - 1] != '*')) break;
            dp[0][i] = true;
            for (int j = 0; j <= ns; j++) ndp[j][i] = true;
        }

        for (int i = 1; i <= ns; i++) {
            for (int j = 1; j <= np; j++) {
                if (p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = ndp[i][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1]);
                }
                ndp[i][j] = (ndp[i - 1][j] | dp[i][j]); 
            }
        }

        return dp[ns][np];

    }
};