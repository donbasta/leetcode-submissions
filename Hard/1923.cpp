class Solution {
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int mn = INT_MAX;
        int psz = paths.size();
        for (auto p : paths) mn = min(mn, (int) p.size());
        int l = 0, r = mn, ans = 0;
        int MOD[] = {1000000009, 1000000007};
        int B[] = {100153, 100003};
        const function<int(int, int, int)> fpow = [&](int a, int b, int mod) -> int {
            int ret = 1;
            while (b) {
                if (b & 1) ret = (1ll * ret * a) % mod;
                a = (1ll * a * a) % mod;
                b >>= 1;
            }
            return ret;
        };
        int inv[] = {fpow(B[0], MOD[0] - 2, MOD[0]), fpow(B[1], MOD[1] - 2, MOD[1])};
        int pw[2][mn + 1];
        for (int x = 0; x < 2; x++) {
            pw[x][0] = 1;
            for (int i = 1; i <= mn; i++) {
                pw[x][i] = (1ll * pw[x][i - 1] * B[x]) % MOD[x];
            }
        }
        const function<bool(int)> ok = [&](int len) -> bool {
            unordered_map<long long, set<int>> cnt;
            int idx = 0;
            for (auto p : paths) {
                int cur[2];
                cur[0] = cur[1] = 0;
                for (int x = 0; x < 2; x++) {
                    for (int i = 0; i < len; i++) {
                        cur[x] = (1ll * (p[i] + 1) * pw[x][i] + cur[x]) % MOD[x];
                    }
                }
                cnt[(1ll * cur[0]) << 32 | cur[1]].insert(idx);
                // cnt[make_pair(cur[0], cur[1])].insert(idx);
                for (int i = len; i < (int) p.size(); i++) {
                    for (int x = 0; x < 2; x++) {
                        cur[x] = (1ll * cur[x] + 1ll * (p[i] + 1) * pw[x][len]) % MOD[x];
                        cur[x] = (cur[x] - (p[i - len] + 1)) % MOD[x];
                        cur[x] = (1ll * cur[x] * inv[x]) % MOD[x];
                        if (cur[x] < 0) cur[x] += MOD[x];
                    }
                    cnt[(1ll * cur[0]) << 32 | cur[1]].insert(idx);
                    // cnt[make_pair(cur[0], cur[1])].insert(idx);
                }
                idx++;
            }
            for (auto e : cnt) {
                if ((int) e.second.size() == psz) {
                    return true;
                }
            }
            return false;
        };
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (ok(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};