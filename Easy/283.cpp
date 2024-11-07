class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int ki = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) nums[ki++] = nums[i];
        }
        for (int i = ki; i < n; i++) nums[i] = 0;
    }
};