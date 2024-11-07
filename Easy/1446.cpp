class Solution {
public:
    int maxPower(string s) {
        int n = s.length();
        int st = 0;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                ans = max(ans, i - st);
                st = i;
            }
        }
        ans = max(ans, n - st);
        return ans;
    }
};