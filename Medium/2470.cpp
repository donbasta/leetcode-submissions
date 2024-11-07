class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        const int M = 1000;
        for (int i = 0; i < n; i++) {
            int kpk = nums[i];
            ans += (kpk == k);
            for (int j = i + 1; j < n; j++) {
                long long cur = kpk * (nums[j] / __gcd(nums[j], kpk));
                if (cur > 1ll * M) break;
                ans += (k == cur);
                kpk = cur;
            }
        }
        return ans;
    }
};