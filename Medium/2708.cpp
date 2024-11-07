class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long ans = -1e18;
        int n = nums.size();
        for (int i = 1; i < (1 << n); i++) {
            long long tmp = 1;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) tmp *= nums[j];
            }
            ans = max(ans, tmp);
        }
        return ans;
    }
};