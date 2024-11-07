class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int tot = accumulate(nums.begin(), nums.end(), 0);
        int L = 0;
        for (int i = 0; i < n; i++) {
            if (L * 2 + nums[i] == tot) return i;
            L += nums[i];
        }
        return -1;
    }
};