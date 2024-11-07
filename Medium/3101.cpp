class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i += 2) {
            nums[i] = 1 - nums[i];
        }
        long long ans = 0;
        int cur = nums[0], start = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] == cur) continue;
            else {
                int len = i - start;
                ans += 1ll * len * (len + 1) / 2;
                start = i;
                cur = nums[i];
            }
        }
        int len = n - start;
        ans += 1ll * len * (len + 1) / 2;
        return ans;
    }
};