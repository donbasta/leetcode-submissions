class Solution {
public:
    int primePalindrome(int n) {
        string sn = to_string(n);
        int len = sn.length();
        int st = stoi(sn.substr(0, (len + 1) / 2));

        auto gen = [&](int x, int flag) -> int {
            string sx = to_string(x);
            int len = sx.length();
            if (flag) len--;
            for (int i = len - 1; i >= 0; i--) {
                sx.push_back(sx[i]);
            }
            return stoi(sx);
        };

        auto is_prime = [&](int tmp) -> bool {
            if (tmp == 1) return false;
            if (tmp <= 3) return true;
            if (tmp % 2 == 0) return false;
            for (int i = 3; i * i <= tmp; i += 2) {
                if (tmp % i == 0) return false;
            }
            return true;
        };

        int cur = len & 1;
        auto next = [&]() {
            int nx = st + 1;
            if (to_string(nx).length() > to_string(st).length()) {
                if (cur & 1) {
                    nx /= 10;
                }
                cur ^= 1;
            }
            st = nx;
        };

        while (true) {
            int cek = gen(st, cur);
            // cout << cek << '\n';
            if (cek >= n && is_prime(cek)) {
                return cek;
            }
            next();
        }
        return -1;
    }
};