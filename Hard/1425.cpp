class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        set<pair<int, int>> se;
        dp[0] = nums[0];
        se.insert(make_pair(dp[0], 0));
        for (int i = 1; i < n; i++) {
            dp[i] = nums[i];
            dp[i] = max(dp[i], nums[i] + se.rbegin()->first);
            if (i >= k) se.erase(make_pair(dp[i - k], i - k));
            se.insert(make_pair(dp[i], i));
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};