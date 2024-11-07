class Solution {
public:
    string convertToTitle(int columnNumber) {
        columnNumber--;
        if (columnNumber == 0) return "A";
        string ret;
        long long pw = 1;
        long long gap = 0;
        while (true) {
            long long tmp = 1ll * columnNumber - gap;
            if (tmp < 0) break;
            ret.push_back((char) (((tmp / pw) % 26) + 'A'));
            pw *= 26;
            gap += pw;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};