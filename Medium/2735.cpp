class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        // vector<int> mn = nums;
        int mn[n];
        for (int i = 0; i < n; i++) mn[i] = nums[i];
        long long ret = 1e18;
        for (int i = 0; i < n; i++) {
            long long tmp = 1ll * i * x;
            for (int j = 0; j < n; j++) {
                tmp += mn[j];
            }
            ret = min(ret, tmp);
            for (int j = 0; j < n; j++) {
                int prv = j - i - 1;
                if (prv < 0) prv += n;
                mn[j] = min(mn[j], nums[prv]);
            }
        }
        return ret;
    }
};