class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long cur = nums[0];
        long long ans = -1;
        for (int i = 1; i < n - 1; i++) {
            cur += nums[i];
            if (cur > nums[i + 1]) {
                ans = max(ans, cur + nums[i + 1]);
            }
        }
        return ans;
    }
};