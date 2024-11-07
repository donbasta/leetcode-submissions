class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] == 1) continue;
            ret++;
            nums[i] ^= 1;
            nums[i + 1] ^= 1;
            nums[i + 2] ^= 1;
        }
        if ((nums[n - 2] != 1) || (nums[n - 1] != 1)) {
            return -1;
        }
        return ret;
    }
};