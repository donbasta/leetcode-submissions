class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.length();
        using ll = long long;
        ll ans = 0;
        int pref[n][2];
        pref[0][0] = pref[0][1] = 0;
        pref[0][s[0] - '0']++;
        for (int i = 1; i < n; i++) {
            pref[i][0] = pref[i - 1][0];
            pref[i][1] = pref[i - 1][1];
            pref[i][s[i] - '0']++;
        }
        for (int i = 1; i < n - 1; i++) {
            int cur = s[i] - '0';
            ans += 1ll * pref[i - 1][1 - cur] * (pref[n - 1][1 - cur] - pref[i][1 - cur]);
        }
        return ans;
    }
};