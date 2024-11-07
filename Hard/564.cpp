class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.length();
        long long pw10 = 1;
        for (int i = 1; i < len; i++) pw10 *= 10;
        string depan = n.substr(0, (len + 1) / 2);
        long long hoho = stoll(depan);
        long long mn = 2e18;
        string ret = n;
        for (long long i = hoho - 1; i <= hoho + 1; i++) {
            string hehe = to_string(i);
            string A = hehe.substr(0, hehe.length() - 1);
            string B;
            if (len % 2 == 1) {
                B = A;
            } else {
                B = hehe;
            }
            reverse(B.begin(), B.end());
            hehe += B;
            long long dif = abs(stoll(n) - stoll(hehe));
            if (dif == 0) continue;
            if (dif < mn) {
                mn = dif;
                ret = hehe;
            }
        }
        if (stoll(n) == pw10 || stoll(n) == pw10 + 1) {
            if (stoll(n) - (pw10 - 1) <= abs(stoll(n) - stoll(ret))) {
                ret = to_string(pw10 - 1);
            }
        }
        if (stoll(n) == pw10 * 10 - 1) {
            if (2 < abs(stoll(n) - stoll(ret))) {
                ret = to_string(pw10 * 10 + 1);
            }
        }

        return ret;
    }
};