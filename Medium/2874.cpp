class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int mn = min(nums[0], nums[1]);
        int mx = max(nums[0], nums[1]);
        int MN = nums[0] - nums[1];
        int MX = nums[0] - nums[1];
        for (int i = 2; i < n; i++) {
            long long cur;
            if (nums[i] < 0) {
                cur = 1ll * MN * nums[i];
            } else {
                cur = 1ll * MX * nums[i];
            }
            if (cur > 0) {
                ans = max(ans, cur);
            }
            MN = min(MN, mn - nums[i]);
            MX = max(MX, mx - nums[i]);
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }
        return ans;
    }
};