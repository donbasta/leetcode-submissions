class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        int pref[n], suf[n];
        pref[0] = (s[0] == '1');
        for (int i = 1; i < n; i++) {
            pref[i] = (pref[i - 1] + (s[i] == '1'));
        }
        suf[n - 1] = (s[n - 1] == '0');
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = (suf[i + 1] + (s[i] == '0'));
        }
        int ans = INT_MAX;
        for (int i = 0; i <= n; i++) {
            int left = (i > 0 ? pref[i - 1] : 0);
            int right = (i < n ? suf[i] : 0);
            ans = min(ans, left + right);
        }
        return ans;
    }
};