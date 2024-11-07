class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long pref_bawah[n], suf_atas[n];
        for (int i = 0; i < n; i++) {
            pref_bawah[i] = 1ll * (i ? pref_bawah[i - 1] : 0) + grid[1][i];
        }
        for (int i = n - 1; i >= 0; i--) {
            suf_atas[i] = 1ll * (i < (n - 1) ? suf_atas[i + 1] : 0) + grid[0][i];
        }
        long long ans = 1e10;
        for (int i = 0; i < n; i++) {
            long long kiri = (i ? pref_bawah[i - 1] : 0);
            long long kanan = (i < (n - 1) ? suf_atas[i + 1] : 0);
            long long bob_get = max(kiri, kanan);
            ans = min(ans, bob_get);
        }
        return ans;
    }
};