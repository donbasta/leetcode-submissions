class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long cur = 0;
        string ret;
        for (auto c : s) {
            if (c >= '2' && c <= '9') {
                int mul = (c - '0');
                long long nx = cur * mul;
                if (nx >= 1ll * k) {
                    int sisa = k % cur;
                    if (sisa == 0) sisa = cur;
                    return decodeAtIndex(s, sisa);
                }
                cur = nx;
            } else {
                cur++;
                if (cur == k) {
                    ret.push_back(c);
                    return ret;
                }
            }
        }
        return ret;
    }
};