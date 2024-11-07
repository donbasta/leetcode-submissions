class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int tot = accumulate(nums.begin(), nums.end(), 0);
        int le = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (le == tot - le - nums[i]) return i;
            le += nums[i];
        }
        return -1;
    }
};