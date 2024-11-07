class Solution {
public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        const int MOD = 1e9 + 7;
        const function<int(int, int)> fpow = [&](int a, int b) -> int {
            int ret = 1;
            while (b) {
                if (b & 1) ret = (1ll * ret * a) % MOD;
                a = (1ll * a * a) % MOD;
                b >>= 1;
            }
            return ret;
        };
        const int MX = 2e5;
        vector<int> fc(MX + 1), ifc(MX + 1);
        fc[0] = 1;
        for (int i = 1; i <= MX; i++) fc[i] = (1ll * fc[i - 1] * i) % MOD;
        ifc[MX] = fpow(fc[MX], MOD - 2);
        for (int i = MX - 1; i >= 0; i--) ifc[i] = (1ll * ifc[i + 1] * (i + 1)) % MOD;
        const function<int(int, int)> C = [&](int a, int b) -> int {
            if (a < 0 || b < 0 || a < b) return 0;
            int ret = (1ll * fc[a] * ifc[a - b]) % MOD;
            ret = (1ll * ret * ifc[b]) % MOD;
            return ret;
        };
        
        int n = s.length();
        vector<int> cnt(26);
        for (auto c : s) cnt[c - 'a']++;
        vector<pair<int, char>> ve(26);
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) continue;
            ve[i] = make_pair(cnt[i], (char)(i + 'a'));
        }
        sort(ve.begin(), ve.end(), greater<>());
        int sz = ve.size();
        
        if (k <= sz) {
            int mn = ve[k - 1].first;
            int idx = k;
            while (idx < sz && ve[idx].first == mn) idx++;
            int r = idx - 1;
            idx = k - 2;
            while (idx >= 0 && ve[idx].first == mn) idx--;
            int l = idx + 1;
    
            int ans = 1;
            for (int i = 0; i < l; i++) {
                ans = (1ll * ans * cnt[ve[i].second - 'a']) % MOD;
            }
            ans = (1ll * ans * C(r - l + 1, k - l)) % MOD;
            ans = (1ll * ans * fpow(mn, k - l)) % MOD;
            return ans;
        }
        return 0;
    }
};