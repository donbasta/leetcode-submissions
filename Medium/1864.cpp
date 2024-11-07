class Solution {
public:
    int minSwaps(string s) {
        int n = s.length();
        int c[2];
        c[0] = count(s.begin(), s.end(), '0');
        c[1] = n - c[0];
        int ans = INT_MAX;
        for (int i = 0; i < 2; i++) {
            if (c[i] != n - n / 2 || c[1 - i] != n / 2) continue;
            int tmp = 0;
            for (int j = 0; j < n; j += 2) {
                tmp += s[j] - '0' == 1 - i;
            }
            ans = min(ans, tmp);
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};