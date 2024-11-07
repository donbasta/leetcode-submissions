class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sz = nums.size();
        for (auto& num : nums) {
            if (num <= 0 || num > sz) num = sz + 1;
        }
        for (auto& num : nums) {
            int an = abs(num);
            if (an > sz) continue;
            --an;
            if (nums[an] > 0) nums[an] = -1 * nums[an];
        }
        for (int i = 0; i < sz; i++) {
            if (nums[i] >= 0) return i + 1;
        }
        return sz + 1;
    }
};