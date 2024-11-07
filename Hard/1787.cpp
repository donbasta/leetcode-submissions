class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        const int B = 1024;
        const int INF = 1e9;
        vector<vector<int>> freq(k, vector<int>(B));
        vector<vector<int>> dp(k, vector<int>(B, INF));
        vector<vector<int>> unq(k);
        vector<int> tot(k);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            freq[i % k][nums[i]]++;
            tot[i % k]++;
        }
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < B; j++) {
                if (freq[i][j] > 0) unq[i].push_back(j);
            }
        }
        int prv = 0;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < B; j++) {
                //dp[i][j] = ...
                if (i == 0) {
                    dp[i][j] = min(dp[i][j], tot[i] - freq[i][j]);
                } else {
                    for (auto c : unq[i]) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j ^ c] + tot[i] - freq[i][c]);
                    }
                    dp[i][j] = min(dp[i][j], prv + tot[i]);
                }
            }
            prv = INF;
            for (int j = 0; j < B; j++) {
                prv = min(prv, dp[i][j]);
            }
        }
        return dp[k - 1][0];
    }
};