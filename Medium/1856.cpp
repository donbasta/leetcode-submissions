class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        int le[n], ri[n];
        memset(le, -1, sizeof(le));
        for (int i = 0; i < n; i++) ri[i] = n;
        vector<pair<int, int>> ve;
        for (int i = 0; i < n; i++) {
            while (!ve.empty() && ve.back().first > nums[i]) {
                ri[ve.back().second] = i;
                ve.pop_back();
            }
            ve.emplace_back(nums[i], i);
        }
        ve.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!ve.empty() && ve.back().first > nums[i]) {
                le[ve.back().second] = i;
                ve.pop_back();
            }
            ve.emplace_back(nums[i], i);
        }
        long long pre[n];
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }
        long long ret = 0;
        for (int i = 0; i < n; i++) {
            int L = le[i] + 1, R = ri[i] - 1;
            long long sum = pre[R] - (L ? pre[L - 1] : 0);
            ret = max(ret, sum * nums[i]);
        }
        const int MOD = 1e9 + 7;
        return (ret % MOD);
    }
};