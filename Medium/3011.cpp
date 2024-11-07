class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<int> cp = nums;
        sort(cp.begin(), cp.end());
        int st = 0;
        int cur = __builtin_popcount(nums[0]);
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            int now = __builtin_popcount(nums[i]);
            if (now != cur) {
                sort(nums.begin() + st, nums.begin() + i);
                st = i;
                cur = now;
            }
        }
        sort(nums.begin() + st, nums.end());
        return cp == nums;
    }
};