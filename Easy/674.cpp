class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cur = 1;
        int ans = 1;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                cur++;
            } else {
                cur = 1;
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};