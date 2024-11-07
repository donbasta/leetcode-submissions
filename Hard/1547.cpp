class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        int k = cuts.size();
        vector<vector<int>> dp(k + 1, vector<int>(k + 1));
        for (int len = 2; len <= k + 1; len++) {
            for (int i = 0; i + len - 1 <= k; i++) {
                int tmp = INT_MAX;
                int lmao = ((i + len - 1 < k) ? cuts[i + len - 1] : n) - (i ? cuts[i - 1] : 0);
                for (int j = i; j < i + len - 1; j++) {
                    tmp = min(tmp, lmao + dp[i][j] + dp[j + 1][i + len - 1]);
                }
                dp[i][i + len - 1] = tmp;
            }
        }
        return dp[0][k];
    }
};