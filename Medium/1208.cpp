class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int pref[n + 1];
        pref[0] = 0;
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + abs(s[i - 1] - t[i - 1]);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int u = lower_bound(pref, pref + i, pref[i] - maxCost) - pref;
            ans = max(ans, i - u);
        }
        return ans;
    }
};