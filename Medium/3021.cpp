class Solution {
public:
    long long flowerGame(int n, int m) {
        int n1 = n / 2, n2 = n - n1;
        int m1 = m / 2, m2 = m - m1;
        return 1ll * n1 * m2 + 1ll * n2 * m1;
    }
};