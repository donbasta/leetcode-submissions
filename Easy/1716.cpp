class Solution {
public:
    int totalMoney(int n) {
        int last = 0;
        int cur;
        int ret = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 7 == 1) {
                cur = last + 1;
                last++;
            } else {
                cur++;
            }
            ret += cur;
        }
        return ret;
    }
};