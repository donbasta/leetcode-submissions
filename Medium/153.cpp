class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int m1 = (l + r) >> 1;
            int m2 = m1 + 1;
            if (nums[l] > nums[m1]) {
                r = m1;
            } else if (nums[m2] > nums[r]) {
                l = m2;
            } else if (nums[m1] > nums[m2]) {
                return nums[m2];
            } else {
                return nums[l];
            }
        }
        return nums[l];
    }
};