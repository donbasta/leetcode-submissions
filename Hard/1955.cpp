class Solution {
public:
    const int MOD = 1e9 + 7;

    int modpow(int a, int b) {
        int ret = 1;
        while (b) {
            if (b & 1) ret = (1LL * ret * a) % MOD;
            a = (1LL * a * a) % MOD;
            b >>= 1;
        }
        return ret;
    }

    int countSpecialSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<int> d0(n), d01(n), d012(n);
        int cntZero = 0;
        for (int i = 0; i < n; i++) {
            cntZero += (nums[i] == 0);
            d0[i] = modpow(2, cntZero) - 1;
        }
        for (int i = 1; i < n; i++) {
            int tmp = d01[i - 1];
            if (nums[i] == 1) {
                tmp = (tmp + d0[i - 1]) % MOD;
                tmp = (tmp + d01[i - 1]) % MOD;
            }     
            d01[i] = tmp;   
        }
        for (int i = 2; i < n; i++) {
            int tmp = d012[i - 1];
            if (nums[i] == 2) {
                tmp = (tmp + d01[i - 1]) % MOD;
                tmp = (tmp + d012[i - 1]) % MOD;
            }
            d012[i] = tmp;
        }
        // for (int i = 0; i < n; i++) {
        //     cout << i << ' ' << d0[i] << ' ' << d01[i] << ' ' << d012[i] << '\n';
        // }
        int ans = d012[n - 1];
        if (ans < 0) ans = (ans + MOD) % MOD;
        return ans;
    }
};