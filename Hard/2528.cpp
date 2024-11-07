class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        long long le = 0, ri = 1e12, ans = -1;
        int n = stations.size();
        auto ok = [&](long long coba) -> bool {
            long long tmp = 0;
            for (int i = 0; i <= r; i++) {
                tmp += stations[i];
            }
            vector<long long> cp;
            for (auto s : stations) cp.push_back(s);
            long long sisa = k;
            for (int i = 0; i < n; i++) {
                int kanan = min(i + r, n - 1);
                int kiri = max(i - r, 0);
                if (tmp < coba) {
                    if (sisa < coba - tmp) return false;
                    cp[kanan] += coba - tmp;
                    sisa -= (coba - tmp);
                    tmp = coba;
                }
                if (i < n - 1) {
                    if (i + 1 + r < n) tmp += cp[i + r + 1];
                    if (i + 1 - r > 0) tmp -= cp[i - r];
                }
            }
            return true;
        };

        while (le <= ri) {
            long long mid = (le + ri) >> 1;
            if (ok(mid)) {
                ans = mid;
                le = mid + 1;
            } else {
                ri = mid - 1;
            }
        }
        assert (ans != -1);
        return ans;
    }
};