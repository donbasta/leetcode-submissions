class Solution {
public:
    string baseNeg2(int n) {
        int t = 0;
        string ret;
        if (n == 0) return "0";
        while (n) {
            if (n & 1) {
                ret.push_back('1');
                if (t & 1) {
                    n++;
                } else {
                    n--;
                }
            } else {
                ret.push_back('0');
            }
            t++;
            n >>= 1;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};