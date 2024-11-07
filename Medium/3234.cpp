class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int n = s.length();
        int bat = sqrt(n);

        int r[n];
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') r[i] = i;
            else r[i] = (i + 1 < n ? r[i + 1] : n);
        }

        for (int i = 0; i < n; i++) {
            int j = r[i];
            ans += (j - i);
            int c1 = j - i, c0 = 1;
            while (c0 <= bat && j < n) {
                int add = max(0, c0 * c0 - c1);
                int af = j + 1 < n ? r[j + 1] : n;
                ans += max(0, af - j - add);
                c1 += af - 1 - j;
                c0++;
                j = af;
            }
        }
        return ans;
    }
};