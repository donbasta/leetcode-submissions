class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long tot = accumulate(nums.begin(), nums.end(), 0ll);
        long long cur = 0;
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            cur += nums[i];
            if (2 * cur >= tot) ans++;
        }
        return ans;
    }
};