class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        using ll = long long;
        map<ll, ll> mp, dp;
        for (auto p : power) {
            mp[p] += p;
        }
        sort(power.begin(), power.end());
        power.resize(unique(power.begin(), power.end()) - power.begin());
        int sz = power.size();

        vector<ll> mx(sz);
        dp[power[0]] = mp[power[0]];
        ll ans = dp[power[0]];
        mx[0] = ans;
        for (int i = 1; i < sz; i++) {
            if (power[i - 1] < power[i] - 2) {
                dp[power[i]] = mx[i - 1] + mp[power[i]];
            } else if (i >= 2 && power[i - 2] < power[i] - 2) {
                dp[power[i]] = mx[i - 2] + mp[power[i]];
            } else if (i >= 3) {
                dp[power[i]] = mx[i - 3] + mp[power[i]];
            } else {
                dp[power[i]] = mp[power[i]];
            }
            mx[i] = max(mx[i - 1], dp[power[i]]);
            ans = max(ans, dp[power[i]]);
        }
        return ans;
    }
};