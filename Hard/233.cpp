class Solution {
public:
    int countDigitOne(int n) {
        string sn = to_string(n);
        int len = sn.length();
        int ans = 0;
        int prv = 0;
        int pw10[10];
        pw10[0] = 1;
        for (int i = 1; i < 10; i++) pw10[i] = pw10[i - 1] * 10;
        for (int i = 0; i < len; i++) {
            int cur = sn[i] - '0';
            int rem = len - i - 1;
            if (rem >= 1) ans += cur * pw10[rem - 1] * rem;
            if (cur > 1) ans += pw10[rem];
            ans += prv * cur * pw10[rem];
            prv += cur == 1;
        }
        ans += prv;
        return ans;
    }
};