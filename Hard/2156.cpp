class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int tmp = 0;
        int p = 1;
        int n = s.size();

        for (int i = n - (k - 1); i < n; i++) {
            tmp = (1ll * tmp + 1ll * p * (s[i] - 'a' + 1)) % modulo;
            p = (1ll * p * power) % modulo;
        }

        int idx = -1;
        for (int i = n - k; i >= 0; i--) {
            tmp = (1ll * tmp * power) % modulo;
            tmp = (tmp + (s[i] - 'a' + 1)) % modulo;
            if (tmp == hashValue) {
                idx = i;
            }
            tmp = (1ll * tmp - 1ll * p * (s[i + k - 1] - 'a' + 1)) % modulo;
            if (tmp < 0) tmp += modulo;
        }

        assert (idx != -1);
        return s.substr(idx, k);
    }
};