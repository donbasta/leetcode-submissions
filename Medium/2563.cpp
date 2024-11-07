class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int needl = lower - nums[i];
            int needr = upper - nums[i];
            int a = lower_bound(nums.begin() + i + 1, nums.end(), needl) - nums.begin();
            int b = upper_bound(nums.begin() + i + 1, nums.end(), needr) - nums.begin();
            ans += (b - a);
        }
        return ans;
    }
};