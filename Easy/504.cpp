class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string ret;
        bool neg = false;
        if (num < 0) {
            neg = true;
            num = abs(num);
        }
        while (num) {
            ret += (char)((num % 7) + '0');
            num /= 7;
        }
        if (neg) ret += '-';
        reverse(ret.begin(), ret.end());
        return ret;
    }
};