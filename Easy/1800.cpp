class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int tot = nums[0];
        int ans = tot;
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) {
                tot = nums[i];
            } else {
                tot += nums[i];
            }
            ans = max(ans, tot);
        }
        return ans;
    }
};