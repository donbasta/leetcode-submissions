class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (nums[i] >= k) return i;
        }
        return n;
    }
};