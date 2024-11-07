class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        if (n <= 10) return 0;
        string s = to_string(n);
        int len = s.length();
        int beda = 9;
        int cur = 9;
        for (int i = 2; i < len; i++) {
            cur *= (11 - i);
            beda += cur;
        }
        auto choose = [&](int x, int y) -> int {
            int ret = 1;
            for (int i = x; i >= x - y + 1; i--) {
                ret *= i;
            } 
            return ret;
        };
        vector<int> cnt(10);
        for (int i = 0; i < len; i++) {
            int cur_dig = s[i] - '0';
            int st = (i == 0 ? 1 : 0);
            int now = choose(9 - i, len - 1 - i);
            for (int j = st; j < cur_dig; j++) {
                if (cnt[j] > 0) continue;
                beda += now;
            }
            cnt[cur_dig]++;
            if (cnt[cur_dig] >= 2) {
                break;
            }
        }
        if (*max_element(cnt.begin(), cnt.end()) <= 1) beda++;
        return n - beda;
    }
};