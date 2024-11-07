class Solution {
public:
    int mySqrt(int x) {
        long long lx = x;
        long long l = 0, r = 1e9;
        long long ans = -1;
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (mid * mid <= lx) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};