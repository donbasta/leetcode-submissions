class Solution {
public:
    int smallestNumber(int n, int t) {
        auto check = [&](int x) -> bool {
            int prod = 1;
            while (x) {
                prod *= (x % 10);
                x /= 10;
            }
            return (prod % t == 0);
        };
        while (true) {
            if (check(n)) return n;
            n++;
        }
        return -1;
    }
};