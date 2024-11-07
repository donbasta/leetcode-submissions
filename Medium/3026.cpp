class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, long long> mn;
        int n = nums.size();
        const long long INF = 1e18;
        long long tmp = 0, ans = -INF;
        for (int i = 0; i < n; i++) {
            tmp += nums[i];
            if (mn.find(nums[i] + k) != mn.end()) {
                ans = max(ans, tmp - mn[nums[i] + k]);
            }
            if (mn.find(nums[i] - k) != mn.end()) {
                ans = max(ans, tmp - mn[nums[i] - k]);
            }
            if (mn.find(nums[i]) == mn.end()) {
                mn[nums[i]] = tmp - nums[i];
            } else {
                mn[nums[i]] = min(mn[nums[i]], tmp - nums[i]);
            }
        }
        if (ans == -INF) ans = 0;
        return ans;
    }
};