class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int last = nums[0];
        int ans = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] > last) {
                last = nums[i];
            } else {
                ans += (last + 1 - nums[i]);
                last++;
            }
        }
        return ans;
    }
};