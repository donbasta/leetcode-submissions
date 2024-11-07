class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        using ll = long long;
        auto sum_dig = [&](ll x) -> int {
            int tot = 0;
            while (x) { tot += x % 10, x /= 10; }
            return tot;
        };

        ll cn = n;
        int ans = 0;
        ll pw = 10;
        while (sum_dig(n) > target) {
            n = ((n + pw - 1) / pw) * pw;
            pw *= 10;
        }
        return n - cn;
    }
};