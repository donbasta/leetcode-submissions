class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long lo = 1, hi = 2e9;
        long long lcm_ab = 1ll * a * b / __gcd(a, b);
        long long lcm_ac = 1ll * a * c / __gcd(a, c);
        long long lcm_bc = 1ll * c * b / __gcd(c, b);
        long long lcm_abc = 1ll * a * lcm_bc / __gcd(1ll * a, lcm_bc);
        long long ans;
        while (lo <= hi) {
            long long mid = (lo + hi) >> 1;
            long long x = (mid / a) + (mid / b) + (mid / c);
            x -= (mid / lcm_ab + mid / lcm_ac + mid / lcm_bc);
            x += mid / lcm_abc;
            if (x >= 1ll * n) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return (int) ans;
    }
};