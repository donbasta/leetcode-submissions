class Solution {
public:
    int minimumTime(string s) {
        int n = s.length();
        int mx = 0;
        int cur = 0;
        int ans = n;
        for (int i = 0; i < n; i++) {
            cur += 2 * (s[i] == '1');
            cur--;
            ans = min(ans, cur - mx + n);
            mx = max(mx, cur);
        }
        return ans;
    }
};