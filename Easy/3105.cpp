class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int inc = 1, dec = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                inc++, ans = max(ans, inc);
            } else {
                inc = 1;
            }
            if (nums[i] < nums[i - 1]) {
                dec++, ans = max(ans, dec);
            } else {
                dec = 1;
            }
        }
        return ans;
    }
};