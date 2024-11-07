class Solution {
public:


    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        int dp[n];
        int f[n][n];
        for (int i = 0; i < n; i++) dp[i] = 2e9;
        dp[0] = k;
        for (int i = 0; i < n; i++) {
            int cnt[n];
            memset(cnt, 0, sizeof(cnt));
            f[i][i] = k;
            cnt[nums[i]]++;
            int unq = 1;
            for (int j = i + 1; j < n; j++) {
                if (cnt[nums[j]] == 0) unq++;
                else if (cnt[nums[j]] == 1) unq--;
                f[i][j] = k + (j - i + 1 - unq);
                cnt[nums[j]]++;
            }
        }
        for (int i = 1; i < n; i++) {
            dp[i] = f[0][i];
            for (int j = i - 1; j >= 0; j--) {
                dp[i] = min(dp[i], dp[j] + f[j + 1][i]);
            }
        }
        return dp[n - 1];
    }
};