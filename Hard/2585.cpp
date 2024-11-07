class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<int> dp(target + 1);
        dp[0] = 1;
        const int MOD = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            vector<int> ndp(target + 1);
            int cnt = types[i][0];
            int m = types[i][1];
            for (int j = 0; j <= target; j++) {
                for (int k = 0; k <= cnt; k++) {
                    if (k * m > j) break;
                    ndp[j] = (ndp[j] + dp[j - k * m]) % MOD;
                }
            }
            dp = ndp;
        }
        return dp[target];
    }
};