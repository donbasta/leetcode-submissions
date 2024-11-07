class Solution {
public:
    long long appealSum(string s) {
        int n = s.length();
        const function<long long(int)> count = [&](int len) -> long long {
            return 1ll * (len) * (len + 1) / 2;
        };

        long long ans = 0;
        long long all = count(n);
        for (int i = 0; i < 26; i++) {
            long long tmp = 0;
            int len = 0;
            for (int j = 0; j < n; j++) {
                if (s[j] - 'a' == i) {
                    tmp += count(len);
                    len = 0;
                } else {
                    len++;
                }
            }
            tmp += count(len);
            ans += (all - tmp);
        }
        return ans;
    }
};