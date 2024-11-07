class Solution {
public:
    int minimumSum(vector<int>& nums) {        
        int n = nums.size();
        vector<int> pr(n), su(n);
        pr[0] = nums[0];
        for (int i = 1; i < n; i++) pr[i] = min(pr[i - 1], nums[i]);
        su[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) su[i] = min(su[i + 1], nums[i]);
        int ret = INT_MAX;
        for (int i = 1; i < n - 1; i++) {
            int ki = pr[i - 1], ka = su[i + 1];
            if (ki < nums[i] && ka < nums[i]) {
                ret = min(ret, ki + ka + nums[i]);
            }
        }
        if (ret == INT_MAX) return -1;
        return ret;
    }
};