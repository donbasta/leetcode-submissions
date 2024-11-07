class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int dp[target + 1];
        memset(dp, 0, sizeof(dp));
        const int MOD = 1e9 + 7;
        dp[0] = 1;
        while (n--) {
            for (int j = target; j >= 0; j--) {
                int& tmp = dp[j] = 0;
                for (int kk = min(k, j); kk >= 1; kk--) {
                    tmp += dp[j - kk];
                    if (tmp >= MOD) tmp -= MOD;
                }
            }
        }
        return dp[target];
    }
};