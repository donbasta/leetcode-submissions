class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt = 0;
        int n = s.length();
        for (auto e : s) cnt += (e == '1');
        string ret(n, '0');
        ret[n - 1] = '1';
        for (int i = 0; i < cnt - 1; i++) ret[i] = '1';
        return ret;
    }
};