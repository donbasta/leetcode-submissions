class Solution {
public:
    int maxProduct(string s) {
        int n = s.length();
        bool is_pal[1 << n];
        memset(is_pal, false, sizeof(is_pal));
        for (int i = 0; i < (1 << n); i++) {
            vector<int> idx;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) idx.push_back(j);
            }
            bool ok = true;
            for (int j = 0; j < (int)idx.size() / 2; j++) {
                if (s[idx[j]] != s[idx[idx.size() - 1 - j]]) {
                    ok = false;
                    break;
                }
            }
            is_pal[i] = ok;
        }
        int ans = 0;
        for (int i = 1; i < (1 << n); i++) {
            if (!is_pal[i]) continue;
            int l1 = __builtin_popcount(i);
            int comp = ((1 << n) - 1) ^ i;
            for (int j = comp; j; j = (j - 1) & comp) {
                if (!is_pal[j]) continue;
                ans = max(ans, l1 * __builtin_popcount(j));
            }
        }
        return ans;
    }
};