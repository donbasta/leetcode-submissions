class Solution {
public:
    string largestPalindrome(int n, int k) {
        string ret(n, '\0');
        if (k == 1 || k == 3 || k == 9) {
            for (int i = 0; i < n; i++) ret[i] = '9';
            return ret;
        } else if (k == 2) {
            ret[0] = ret.back() = '8';
            for (int i = 1; i < n - 1; i++) ret[i] = '9';
            return ret;
        } else if (k == 4) {
            if (n == 1) return "8";
            ret[0] = ret[1] = ret[n - 2] = ret[n - 1] = '8';
            for (int i = 2; i < n - 2; i++) ret[i] = '9';
            return ret;
        } else if (k == 5) {
            ret[0] = ret.back() = '5';
            for (int i = 1; i < n - 1; i++) ret[i] = '9';
            return ret;
        } else if (k == 6) {
            if (n == 1) return "6";
            if (n == 2) return "66";
            for (int i = 0; i < n; i++) ret[i] = '9';
            if (n & 1) {
                ret[0] = ret.back() = ret[n / 2] = '8';
                return ret;
            }
            ret[0] = ret.back() = '8';
            ret[n / 2] = ret[n / 2 - 1] = '7';
            return ret;
        } else if (k == 8) {
            if (n == 1) return "8";
            if (n == 2) return "88";
            ret[0] = ret[1] = ret[2] = ret[n - 3] = ret[n - 2] = ret[n - 1] = '8';
            for (int i = 3; i < n - 3; i++) ret[i] = '9';
            return ret;
        }
        //k == 7
        for (int i = 0; i < n; i++) ret[i] = '9';
        vector<int> pw(n);
        pw[0] = 1;
        for (int i = 1; i < n; i++) {
            pw[i] = (pw[i - 1] * 10) % 7;
        }
        if (n & 1) {
            int cur = 0;
            for (int i = 0; i < n; i++) {
                if (i == (n / 2)) continue;
                cur = (cur + 9 * pw[i]) % 7;
            }
            for (int i = 9; i >= 0; i--) {
                if ((cur + i * pw[n / 2]) % 7 == 0) {
                    ret[n / 2] = (char)(i + '0');
                    return ret;
                }
            }
        }
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (i == (n / 2) || (i == (n / 2) - 1)) continue;
            cur = (cur + 9 * pw[i]) % 7;
        }
        for (int i = 9; i >= 0; i--) {
            if ((cur + i * pw[n / 2] + i * pw[n / 2 - 1]) % 7 == 0) {
                ret[n / 2] = ret[n / 2 - 1] = (char)(i + '0');
                return ret;
            }
        }
        return "-1";
    }
};