class Solution {
public:
    long long kMirror(int k, int n) {
        int cnt_dig = 1;
        int cnt = 0;
        long long ans = 0;
        long long pw[20];
        pw[0] = 1;
        for (int i = 1; i < 20; i++) pw[i] = pw[i - 1] * k;
        bool udah = false;
        auto is_palindrome = [&](string s) -> bool {
            int n = s.length();
            for (int i = 0; i < (n / 2); i++) {
                if (s[i] != s[n - 1 - i]) return false;
            }
            return true;
        };
        while (true) {
            int x = (cnt_dig + 1) / 2;
            for (long long i = pw[x - 1]; i < pw[x]; i++) {
                long long tmp = i * pw[cnt_dig - x];
                string s;
                int ni = i;
                while (ni > 0) {
                    s.push_back((char)(ni % k + '0'));
                    ni /= k;
                }
                reverse(s.begin(), s.end());
                for (int j = 0; j < (cnt_dig - x); j++) {
                    tmp += pw[j] * (s[j] - '0');
                }
                string lmao = to_string(tmp);
                if (is_palindrome(lmao)) {
                    cnt++;
                    ans += tmp;
                    if (cnt == n) {
                        udah = true;
                        break;
                    }
                }
            }
            if (udah) break;
            cnt_dig++;
        }
        return ans;
    }
};