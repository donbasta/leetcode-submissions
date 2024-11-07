class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.length();
        int ve[n];
        for (int i = 0; i < n; i++) {
            ve[i] = (s[i] - 'a') - i;
            ve[i] %= 26;
            if (ve[i] < 0) ve[i] += 26;
        }
        int lg[26], rg[n];
        memset(lg, 0, sizeof(lg));
        rg[n - 1] = n;
        for (int i = n - 2; i >= 0; i--) {
            if (ve[i] == ve[i + 1]) rg[i] = rg[i + 1];
            else rg[i] = i + 1;
        }
        for (int i = 0; i < n; i++) {
            int cur = s[i] - 'a';
            lg[cur] = max(lg[cur], rg[i] - i);
        }
        return accumulate(lg, lg + 26, 0);
    }
};