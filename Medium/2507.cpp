class Solution {
public:
    int smallestValue(int n) {
        int cur = n;
        while (true) {
            int tmp = 0;
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    while (n % i == 0) tmp += i, n /= i;
                }
            }
            if (n > 1) tmp += n;
            if (tmp == cur) break;
            cur = tmp;
            n = cur;
        }
        return cur;
    }
};