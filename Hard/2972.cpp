class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        while (j > 0 && nums[j] > nums[j - 1]) {
            j--;
        }
        if (j == 0) {
            return 1ll * n * (n + 1) / 2;
        }
        long long ans = n - j + 1;
        while (true) {
            int ki = nums[i];
            while (j < n && nums[j] <= ki) j++;
            ans += n - j + 1;
            if (nums[i + 1] <= nums[i]) break;
            i++;
        }
        return ans;
    }
};