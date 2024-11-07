class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int m1 = (l + r) >> 1;
            int m2 = m1 + 1;
            if (nums[l] > nums[m1]) { //pivot in interval [l, m1]
                if (target <= nums[r] && target >= nums[m2]) {
                    l = m2;
                } else {
                    r = m1;
                }
            } else if (nums[m2] > nums[r]) { //pivot in interval [m2, r]
                if (target <= nums[m1] && target >= nums[l]) {
                    r = m1;
                } else {
                    l = m2;
                }
            } else if (nums[m1] > nums[m2]) { //pivot di m1 ke m2
                if (target >= nums[l]) {
                    r = m1;
                } else {
                    l = m2;
                }
            } else { //sorted
                if (nums[m1] < target) {
                    l = m2;
                } else {
                    r = m1;
                }
            }
        }
        if (nums[l] != target) return -1;
        return l;
    }
};