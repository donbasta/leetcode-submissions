class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        int pref[n];
        pref[0] = (nums[0] % p == 0);
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + (nums[i] % p == 0);
        }
        
        const function<int(int, int, int)> fpow = [&](int a, int b, int mod) -> int {
            int ret = 1;
            while (b) {
                if (b & 1) ret = (1ll * ret * a) % mod;
                a = (1ll * a * a) % mod;
                b >>= 1;
            }
            return ret;
        };

        const int M1 = 1e9 + 7, M2 = 1e9 + 9;
        int B[] = {211, 223};
        int M[] = {M1, M2};
        int pre[2][n];
        for (int i = 0; i < 2; i++) {
            int pw = B[i];
            pre[i][0] = nums[0];
            for (int j = 1; j < n; j++) {
                pre[i][j] = (1ll * pre[i][j - 1] + 1ll * nums[j] * pw) % M[i];
                pw = (1ll * pw * B[i]) % M[i];
            }
        }

        const function<long long(int, int)> hash = [&](int a, int b) -> long long {
            long long ret[2];
            for (int i = 0; i < 2; i++) {
                int tmp = pre[i][b] - (a ? pre[i][a - 1] : 0);
                tmp = (1ll * tmp * fpow(B[i], M[i] - 1 - a, M[i])) % M[i];
                if (tmp < 0) tmp += M[i];
                ret[i] = tmp;
            }
            return ((ret[0] << 32) | ret[1]);
        };

        unordered_map<long long, int> ump;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int cnt = pref[j] - (i ? pref[i - 1] : 0);
                if (cnt > k) continue;
                ump[hash(i, j)]++;
            }
        }
        return ump.size();
    }
};