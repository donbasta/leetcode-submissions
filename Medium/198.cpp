class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[1] = nums[0];
        int tmp = 0;
        for (int i = 1; i < n; i++) {
            dp[i + 1] = nums[i] + tmp;
            tmp = max(tmp, dp[i]);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};