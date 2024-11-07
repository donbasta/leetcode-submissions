class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lo = 1, hi = m * n;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int lt = 0, lte = 0;
            for (int i = 1; i <= m; i++) {
                // i, 2i, ... ij <= mid-1
                // i, 2i, .... ij <= mid
                lt += min(n, (mid - 1) / i);
                lte += min(n, mid / i);
            }
            if (lt < k && lte >= k) {
                return mid;
            }
            if (lte < k) {
                lo = mid + 1;
            } else if (lt >= k) {
                hi = mid - 1;
            }
        }
        return lo;
    }
};