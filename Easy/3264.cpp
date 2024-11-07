class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        for (int i = 1; i <= k; i++) {
            int mn = INT_MAX;
            int pos = -1;
            for (int j = 0; j < n; j++) {
                if (nums[j] < mn) {
                    mn = nums[j];
                    pos = j;
                }
            }
            nums[pos] *= multiplier;
        }
        return nums;
    }
};