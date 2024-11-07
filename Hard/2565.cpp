class Solution {
public:
    int minimumScore(string s, string t) {
        int ns = s.length(), nt = t.length();
        int ps = 0;
        vector<int> pre(nt, -1), suf(nt, -1);
        for (int i = 0; i < nt; i++) {
            while (ps < ns && s[ps] != t[i]) ps++;
            if (ps == ns) break;
            pre[i] = ps;
            ps++;
        }
        ps = ns - 1;
        for (int i = nt - 1; i >= 0; i--) {
            while (ps >= 0 && s[ps] != t[i]) ps--;
            if (ps == -1) break;
            suf[i] = ps;
            ps--;
        }
        const int INF = 2e9;
        int lol = upper_bound(suf.begin(), suf.end(), -1) - suf.begin();
        int ans = lol;
        for (int i = 0; i < nt; i++) {
            if (pre[i] == -1) break;
            int hehe = upper_bound(suf.begin() + i + 1, suf.end(), pre[i]) - suf.begin();
            ans = min(ans, hehe - i - 1);
        }
        return ans;
    }
};