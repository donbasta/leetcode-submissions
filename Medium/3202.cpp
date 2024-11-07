class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        for (auto& e : nums) e %= k;
        int n = nums.size();
        int ans = 0;
        vector<vector<int>> dp(k, vector<int>(k, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                dp[nums[i]][j] = max(dp[nums[i]][j], dp[j][nums[i]] + 1);
            }
        }
        for (int i = 0; i < k; i++) for (int j = 0; j < k; j++) ans = max(ans, dp[i][j]);
        return ans;
    }
};