class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if (k == 0) {
            return nums.back() - nums[0];
        }
        int n = nums.size();
        unordered_map<int, bool> ump;
        for (auto c : nums) ump[c] = true;
        int ans = INT_MAX;
        for (int i = nums[0] - k; i <= nums[0] + k; i++) {
            if (!ump.count(i - k) && !ump.count(i + k)) continue;
            int mx = i;
            int l = lower_bound(nums.begin(), nums.end(), i) - nums.begin();
            if (l > 0) mx = max(mx, nums[l - 1] + k);
            int r = lower_bound(nums.begin(), nums.end(), i + k) - nums.begin();
            if (r < n) mx = max(mx, nums.back() - k);
            if (r > 0) mx = max(mx, nums[r - 1] + k);
            ans = min(ans, mx - i);
        }
        return ans;
    }
};