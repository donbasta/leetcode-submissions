class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ret = 1;
        int cur = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] != cur) {
                ret++;
                cur = nums[i];
            }
        }
        if (nums[0] == 1) ret--;
        return ret;
    }
};