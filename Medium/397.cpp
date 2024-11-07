class Solution {
public:
    int integerReplacement(int n) {
        using ll = long long;
        ll ans = n - 1;
        int tmp = 0;
        ll ln = n;
        while (ln > 1) {
            if (ln & 1) {
                if (ln % 4 == 1) ln--;
                else ln++;
            } else {
                ln /= 2;
            }
            tmp++;
            ans = min(ans, tmp + ln - 1);
        }
        return ans;
    }
};