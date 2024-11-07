class Solution {
public:
    long long cnt_terminal_zeroes_fact(long long x) {
        long long s5 = 0;
        long long tmp = x;
        while (tmp) {
            s5 += tmp % 5;
            tmp /= 5;
        }
        return (x - s5) / 4;
    }

    int preimageSizeFZF(int k) {
        long long l = 0, r = 1e18;
        long long lb, rb;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            long long cnt = cnt_terminal_zeroes_fact(mid);
            if (cnt < k) {
                l = mid + 1;
            } else {
                lb = mid;
                r = mid - 1;
            }
        }
        l = 0, r = 1e18;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            long long cnt = cnt_terminal_zeroes_fact(mid);
            if (cnt > k) {
                r = mid - 1;
            } else {
                rb = mid;
                l = mid + 1;
            }
        }
        return (rb - lb + 1);
    }
};