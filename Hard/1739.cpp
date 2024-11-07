class Solution {
public:
    int minimumBoxes(int n) {
        int lo = 1, hi = n - 1, piv = n;

        auto get = [&](int B) -> pair<int, int> {
            int le = 0, ri = B, piv = -1;
            while (le <= ri) {
                int mid = (le + ri) >> 1;
                if (1ll * mid * (mid + 1) / 2 > 1ll * B) {
                    ri = mid - 1;
                } else {
                    piv = mid;
                    le = mid + 1;
                }
            }
            return make_pair(piv, B - piv * (piv + 1) / 2);
        };

        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            pair<int, int> P = get(mid);
            int x = P.first, y = P.second;
            if (1ll * (x + 2) * (x + 1) * x / 6 + 1ll * y * (y + 1) / 2 >= 1ll * n) {
                piv = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return piv;
    }
};