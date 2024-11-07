class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n);
        int maxCan = nums[0];
        dp[0] = true;
        for (int i = 1; i < n; i++) {
            if (maxCan >= i) {
                dp[i] = true;
                maxCan = max(maxCan, i + nums[i]);
            }
        }
        return dp[n - 1];
    }
};