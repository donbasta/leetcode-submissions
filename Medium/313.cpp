class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> super_ugly(n);
        int m = primes.size();
        vector<int> idx(m);
        super_ugly[0] = 1;
        for (int i = 1; i < n; i++) {
            long long tmp = INT_MAX;
            for (int j = 0; j < m; j++) {
                tmp = min(tmp, 1ll * primes[j] * super_ugly[idx[j]]);
            }
            super_ugly[i] = tmp;
            for (int j = 0; j < m; j++) {
                if (tmp == 1ll * primes[j] * super_ugly[idx[j]]) {
                    idx[j]++;
                }
            }
        }
        return super_ugly[n - 1];
    }
};