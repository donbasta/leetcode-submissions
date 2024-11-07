class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int len = 0;
        int last = -1;
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (len == 0 && nums[i] % 2 == 0 && nums[i] <= threshold) {
                ans = max(ans, len);
                len = 1;
                last = 0;
            } else if (len > 0 && nums[i] % 2 != last && nums[i] <= threshold) {
                len++;
                last = nums[i] % 2;
            } else {
                ans = max(ans, len);
                if (nums[i] % 2 == 0 && nums[i] <= threshold) len = 1;
                else len = 0;
            }
        }
        ans = max(ans, len);
        return ans;
    }
};