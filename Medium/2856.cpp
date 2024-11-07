class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        if (n == 2) return (2 * (nums[0] == nums[1]));
        sort(nums.begin(), nums.end());
        int mid = (n + 1) / 2;
        int pair = 0;
        for (int i = mid; i < n; i++) {
            pair += (nums[i] > nums[i - mid]);
        }
        return (n - pair * 2);
    }
};