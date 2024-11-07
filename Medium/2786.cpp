class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        int n =  nums.size();
        vector<long long> dp(n);
        dp[0] = nums[0];
        vector<set<long long>> ve(2);
        ve[nums[0] & 1].insert(dp[0]);
        const long long INF = 1e18;
        for (int i = 1; i < n; i++) {
            long long tmp = -INF;
            int par = nums[i] & 1;
            if (!ve[par].empty()) {
                tmp = max(tmp, *ve[par].rbegin() + nums[i]);
            } 
            if (!ve[par ^ 1].empty()) {
                tmp = max(tmp, *ve[par ^ 1].rbegin() + nums[i] - x);
            }
            dp[i] = tmp;
            ve[nums[i] & 1].insert(dp[i]);
        }
        long long ans = -INF;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};