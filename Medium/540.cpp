class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (mid == 0) {
                return nums[mid];
            } else if (mid == nums.size() - 1) {
                return nums[mid];
            } else {
                if (nums[mid] == nums[mid - 1]) {
                    if ((mid - 1) & 1) {
                        r = mid - 2;
                    } else {
                        l = mid + 1;
                    }
                } else if (nums[mid] == nums[mid + 1]) {
                     if (mid & 1) {
                         r = mid - 1;
                     } else {
                         l = mid + 2;
                     }
                } else {
                    return nums[mid];
                }
            }
        }
        return -1;
    }
};