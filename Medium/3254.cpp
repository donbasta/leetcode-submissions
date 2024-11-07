class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) {
            return nums;
        }
        vector<int> ret(n - k + 1, -1);
        int st = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                st = i;
            }
            if (i >= k - 1 && st <= i - k + 1) {
                ret[i - k + 1] = nums[i];
            }
        }
        return ret;
    }
};