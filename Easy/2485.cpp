class Solution {
public:
    int pivotInteger(int n) {
        int all = n * (n + 1) / 2;
        int tmp = 0;
        for (int i = 1; i <= n; i++) {
            tmp += i;
            if (tmp == all - tmp + i) {
                return i;
            }
        }
        return -1;
    }
};