class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        vector<int> pr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        vector<int> can = {6, 10, 14, 15, 21, 22, 26, 30};
        vector<int> ve;
        for (auto p : pr) ve.push_back(p);
        for (auto p : can) ve.push_back(p);
        sort(ve.begin(), ve.end());

        int sz = ve.size();
        vector<bool> sabi(1 << sz);

        sabi[0] = true;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < (1 << i); j++) {
                if (!sabi[j]) continue;
                bool ok = true;
                for (int b = 0; b < i; b++) {
                    if (((j >> b) & 1) && __gcd(ve[i], ve[b]) > 1) {
                        ok = false;
                        break;
                    }
                }
                if (ok) sabi[j ^ (1 << i)] = true;
            }
        }

        const int MOD = 1e9 + 7;

        vector<int> cnt(31);
        for (auto n : nums) cnt[n]++;

        int ans = 0;
        int lmao = 1;
        for (int i = 0; i < cnt[1]; i++) (lmao = 1ll * lmao * 2 % MOD);
        for (int i = 1; i < (1 << sz); i++) {
            if (!sabi[i]) continue;
            int tmp = lmao;
            for (int j = 0; j < sz; j++) {
                if (!((i >> j) & 1)) continue;
                tmp = (1ll * tmp * cnt[ve[j]]) % MOD;
            }
            ans = (ans + tmp) % MOD;
        }
        return ans;
    }
};