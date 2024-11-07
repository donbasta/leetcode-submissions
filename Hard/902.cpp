class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string sn = to_string(n);
        int len = sn.length();
        int sz = digits.size();
        int pw[len + 1];
        pw[0] = 1;
        for (int i = 1; i <= len; i++) pw[i] = pw[i - 1] * sz;
        int ans = 0;
        for (int i = 1; i < len; i++) {
            ans += pw[i];
        }

        vector<int> ada(10), pre(10);
        for (auto d : digits) ada[d[0] - '0']++;
        for (int i = 1; i < 10; i++) pre[i] = (ada[i] + pre[i - 1]);
        bool ok = true;
        for (int i = 0; i < len; i++) {
            int cur = sn[i] - '0';
            //find number of digit in digits which is less than cur
            if (cur == 0) {
                ok = false;
                break;
            }
            ans += pre[cur - 1] * pw[len - 1 - i];
            if (!ada[cur]) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
        return ans;
    }
};