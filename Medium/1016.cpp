class Solution {
public:
    bool queryString(string s, int n) {
        int sz = s.length();
        if (n > sz * (sz + 1) / 2) return false;
        vector<bool> yes(n + 1);
        using ll = long long;
        for (int i = 0; i < sz; i++) {
            ll tmp = 0;
            for (int j = i; j < sz; j++) {
                tmp = (tmp * 2) + (s[j] - '0');
                if (tmp > n) break;
                yes[tmp] = true;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!yes[i]) return false;
        }
        return true;
    }
};