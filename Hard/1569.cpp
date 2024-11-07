class Solution {
public:
    int numOfWays(vector<int>& nums) {
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

        vector<int> fc(1005), ifc(1005);
        fc[0] = 1;
        for (int i = 1; i <= 1000; i++) fc[i] = (1ll * fc[i - 1] * i) % MOD;
        ifc[1000] = fpow(fc[1000], MOD - 2);
        for (int i = 999; i >= 0; i--) ifc[i] = (1ll * ifc[i + 1] * (i + 1)) % MOD;

        const function<int(int, int)> choose = [&](int a, int b) -> int {
            if (a < 0 || b < 0 || a < b) return 0;
            int ret = fc[a];
            ret = (1ll * ret * ifc[b]) % MOD;
            ret = (1ll * ret * ifc[a - b]) % MOD;
            return ret;
        };


        const function<int(vector<int>&)> solve = [&](vector<int>& ve) -> int {
            if (ve.size() <= 2) return 1;
            vector<int> le, ri;
            int n = ve.size();
            for (int i = 1; i < n; i++) {
                if (ve[i] < ve[0]) le.push_back(ve[i]);
                else ri.push_back(ve[i]);
            }
            int ans = (1ll * solve(le) * solve(ri)) % MOD;
            int a = le.size();
            ans = (1ll * ans * choose(n - 1, a)) % MOD;
            return ans;
        };

        int lmao = solve(nums);
        lmao = (lmao + MOD - 1) % MOD;
        return lmao;
    }
};