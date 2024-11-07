class Solution {
public:
    int longestContinuousSubstring(string s) {
        int cur = 1;
        int last = s[0] - 'a';
        int n = s.length();
        int ans = 1;
        for (int i = 1; i < n; i++) {
            int now = s[i] - 'a';
            if (now == last + 1) {
                cur++;
                last = now;
            } else {
                ans = max(ans, cur);
                cur = 1;
                last = s[i] - 'a';
            }
        }
        ans = max(ans, cur);
        return ans;
    }
};