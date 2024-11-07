class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int M = 1e5;
        vector<int> dp(M + 1);
        for (auto e : nums) dp[e] = 1;
        int n = nums.size();

        auto sqrt = [&](int x) -> int {
            int l = 1, r = 1e4, ans = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (mid * mid > x) {
                    r = mid - 1;
                } else {
                    ans = mid;
                    l = mid + 1;
                }
            }
            return ans;
        };

        for (int i = 0; i < n; i++) {
            int x = sqrt(nums[i]);
            if (x * x != nums[i]) continue;
            dp[nums[i]] = max(dp[nums[i]], dp[x] + 1);
        }
        int ans = *max_element(dp.begin(), dp.end());
        return (ans >= 2 ? ans : -1);
    }
};