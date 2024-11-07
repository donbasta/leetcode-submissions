class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long l = 1, r = 1e18;
        int lcm = a * (b / __gcd(a, b));
        long long ans;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            long long cek = (mid / a) + (mid / b) - (mid / lcm);
            if (cek >= n) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        int MOD = 1e9 + 7;
        ans %= MOD;
        return ans;
    }
};