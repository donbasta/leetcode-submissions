class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        while (n > 1) {
            for (int j = 0; j < n / 2; j++) {
                if (j & 1) nums[j] = max(nums[2 * j], nums[2 * j + 1]);
                else nums[j] = min(nums[2 * j], nums[2 * j + 1]);
            }
            n /= 2;
        }
        return nums[0];
    }
};