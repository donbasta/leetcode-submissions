class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int n = s.length();
        if (t.length() != n) return false;
        vector<int> cnt(26);

        auto calc = [&](int x) -> int {
            //from 1, 2, .., n, how many of them equiv x mod 26
            int ret = k / 26 + ((k % 26) >= x);
            return (x ? ret : ret - 1);
        };

        for (int i = 0; i < n; i++) {
            if (s[i] == t[i]) continue;
            int tam = (t[i] + 26 - s[i]) % 26;
            if (tam > k) return false;
            if (cnt[tam] >= calc(tam)) return false;
            cnt[tam]++;
        }
        return true;
    }
};