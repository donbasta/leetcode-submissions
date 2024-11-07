class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        using ll = long long;
        const ll MOD = 1e9 + 7;

        if (n == 1) return 0;
        if (n == 2) return (1ll * cost1 * (nums[1] - nums[0])) % MOD;

       
        ll tot = accumulate(nums.begin(), nums.end(), 0ll);
        
        if (cost1 * 2 <= cost2) {
            ll ans = 1ll * cost1 * (1ll * n * nums.back() - tot);
            ans %= MOD;
            return ans;
        }
        ll need_most = nums.back() - nums[0];
        ll need_other = 1ll * n * nums.back() - tot - need_most;
        if (need_most <= need_other) {
            ll need = need_most + need_other;
            ll ans = (need / 2) * cost2 + (need & 1) * cost1;
            need += n;
            ans = min(ans, (need / 2) * cost2 + (need & 1) * cost1);
            ans %= MOD;
            return ans;
        } else {
            if (cost1 + 1ll * (n - 1) * (cost2 - cost1) >= 0) {
                ll ans = (need_other) * cost2 + (need_most - need_other) * cost1;
                ans %= MOD;
                return ans;
            } else {
                ll add = (need_most - need_other - 1) / (n - 2);
                need_most += add;
                need_other += add * (n - 1);
                ll ans = (need_other) * cost2 + (need_most - need_other) * cost1;
                need_most++;
                need_other += (n - 1);
                ll need = need_other + need_most;
                ans = min(ans, (need / 2) * cost2 + (need & 1) * cost1);
                need += n;
                ans = min(ans, (need / 2) * cost2 + (need & 1) * cost1);
                ans %= MOD;
                return ans;
            }
        }
        return -1;
    }
};