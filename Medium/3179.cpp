class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<int> ret(n, 1);
        for (int i = 0; i < k; i++) {
            for (int j = 1; j < n; j++) {
                ret[j] = (ret[j] + ret[j - 1]) % MOD;
            }
        }
        return ret.back();
    }
};