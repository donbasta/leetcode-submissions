class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n);
        map<int, int> mp;
        mp[0] = -1;
        int cur_sum = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0) dp[i] = dp[i - 1];
            if (mp.count(cur_sum + nums[i] - target)) {
                int prv = mp[cur_sum + nums[i] - target];
                dp[i] = max(dp[i], 1 + (prv >= 0 ? dp[prv] : 0));
            }
            cur_sum += nums[i];
            mp[cur_sum] = i;
        }

        return dp[n - 1];
    }
};