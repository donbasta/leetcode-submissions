class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int dif = 0, n = nums.size(), tot = 0;
        if (n == 1) return 0;
        for (int i = 0; i < n - 1; i++) {
            tot += abs(nums[i + 1] - nums[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            dif = max(dif, abs(nums[i + 1] - nums[0]) - abs(nums[i + 1] - nums[i]));
        }
        for (int i = n - 1; i >= 1; i--) {
            dif = max(dif, abs(nums[i - 1] - nums.back()) - abs(nums[i - 1] - nums[i]));
        }
        const int MX = 1e5;
        int Bmx = -(MX + 1), Bmn = MX + 1;
        int Amx = -(MX + 1), Amn = MX + 1;
        if (nums[n - 2] >= nums[n - 1]) {
            Amx = max(Amx, nums[n - 1]);
            Amn = min(Amn, nums[n - 2]);
        }
        if (nums[n - 2] <= nums[n - 1]) {
            Bmx = max(Bmx, nums[n - 2]);
            Bmn = min(Bmn, nums[n - 1]);
        }
        for (int i = n - 3; i >= 0; i--) {
            if (nums[i] >= nums[i + 1]) {
                dif = max(dif, 2 * (Amx - nums[i]));
                dif = max(dif, 2 * (nums[i + 1] - Amn));
                dif = max(dif, 2 * (Bmx - nums[i]));
                dif = max(dif, 2 * (nums[i + 1] - Bmn));
                Amx = max(Amx, nums[i + 1]);
                Amn = min(Amn, nums[i]);
            }
            if (nums[i] <= nums[i + 1]) {
                dif = max(dif, 2 * (Amx - nums[i + 1]));
                dif = max(dif, 2 * (nums[i] - Amn));
                dif = max(dif, 2 * (Bmx - nums[i + 1]));
                dif = max(dif, 2 * (nums[i] - Bmn));
                Bmx = max(Bmx, nums[i]);
                Bmn = min(Bmn, nums[i + 1]);
            }
        }
        return tot + dif;
    }
};