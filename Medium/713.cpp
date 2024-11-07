class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int r = 0;
        int cur = nums[0];
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (r < i) {
                r = i;
                cur = nums[i];
            }
            while (r < n - 1 && cur < k) {
                r++, cur *= nums[r];
            }
            if (cur >= k) {
                ans += r - i;
            } else if (cur < k) {
                ans += r - i + 1;
            }
            cur /= nums[i];
        }
        return ans;
    }
};