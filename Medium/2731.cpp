class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        using ll = long long;
        int n = nums.size();
        vector<ll> n2(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') n2[i] = 1ll * nums[i] - d;
            else if (s[i] == 'R') n2[i] = 1ll * nums[i] + d;
        }
        sort(n2.begin(), n2.end());
        int cnt = -(n - 1);
        int ans = 0;
        const int MOD = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            ans = (1ll * ans + 1ll * cnt * n2[i]) % MOD;
            cnt += 2;
        }
        if (ans < 0) ans += MOD;
        return ans;
    }
};