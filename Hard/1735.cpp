class Solution {
public:
    const int mod = 1e9 + 7;
    int fpow(int a, int b) {
        int ret = 1;
        while (b) {
            if (b & 1) ret = (1ll * ret * a) % mod;
            a = (1ll * a * a) % mod;
            b >>= 1;
        }
        return ret;
    }
    vector<int> init_fac() {
        const int N = 1e5;
        vector<int> ret(N + 1);
        ret[0] = 1;
        for (int i = 1; i <= N; i++) {
            ret[i] = (1ll * ret[i - 1] * i) % mod;
        }
        return ret;
    }
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        vector<int> factorials = init_fac();
        const function<int(int, int)> C = [&](int a, int b) -> int {
            if (a < 0 || b < 0 || a < b) return 0;
            int choose = (1ll * factorials[a] * fpow(factorials[b], mod - 2)) % mod;
            choose = (1ll * choose * fpow(factorials[a - b], mod - 2)) % mod;
            return choose;
        };
        vector<int> ret;
        for (auto q : queries) {
            int bucket = q[0], prod = q[1];
            vector<int> powers;
            for (int i = 2; i * i <= prod; i++) {
                if (prod % i == 0) {
                    int tmp = 0;
                    while (prod % i == 0) {
                        tmp++, prod /= i;
                    }
                    powers.push_back(tmp);
                }
            }
            if (prod > 1) powers.push_back(1);
            int ans = 1;
            for (auto e : powers) {
                ans = (1ll * ans * C(e + bucket - 1, bucket - 1)) % mod;
            }
            ret.push_back(ans);
        }
        return ret;
    }
};