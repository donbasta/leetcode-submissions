class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int INF = 1e9;
        int n = nums.size();
        vector<int> dp(n, INF);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            int t = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            if (t == n) continue;
            dp[t] = min(dp[t], nums[i]);
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (dp[i] < INF) {
                ans = i + 1;
            }
        }
        return ans;
    }
};