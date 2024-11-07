class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int nx[n][3];
        for (int i = n - 1; i >= 0; i--) {
            int cur = s[i] - 'a';
            for (int j = 0; j < 3; j++) {
                if (j == cur) nx[i][j] = i;
                else {
                    nx[i][j] = (i + 1 < n ? nx[i + 1][j] : n);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int p = max(max(nx[i][0], nx[i][1]), nx[i][2]);
            ans += n - p;
        }
        return ans;
    }
};