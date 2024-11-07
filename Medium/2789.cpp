class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long ans = nums.back();
        long long cur = nums.back();
        int n = nums.size();
        if (n == 1) return ans;
        for (int i = n - 2; i >= 0; i--) {
            if (1ll * nums[i] <= cur) {
                cur += nums[i];
            } else {
                ans = max(ans, cur);
                cur = nums[i];
            }
        }
        ans = max(ans, cur);
        return ans;
    }
};