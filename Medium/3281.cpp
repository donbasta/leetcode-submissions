class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        int n = start.size();
        long long le = 0, ri = 2e9, piv = -1;

        auto ok = [&](long long dif) -> bool {
            long long la = start[0];
            for (int i = 1; i < n; i++) {
                if (la + dif > 1ll * start[i] + d) return false;
                la = max(la + dif, 1ll * start[i]);
            }
            return true;
        };

        while (le <= ri) {
            long long mid = (le + ri) >> 1;
            if (ok(mid)) {
                piv = mid;
                le = mid + 1;
            } else {
                ri = mid - 1;
            }
        }
        return piv;
    }
};