class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        set<int> se;
        se.insert(nums[0]);
        int ans = INT_MAX;
        for (int i = x; i < n; i++) {
            auto A = se.lower_bound(nums[i]);
            if (A != se.end()) ans = min(ans, *A - nums[i]);
            if (A != se.begin()) {
                --A;
                ans = min(ans, nums[i] - *A);
            }
            if (i - x + 1 < n) se.insert(nums[i - x + 1]);
        }
        return ans;
    }
};