class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int l = 0, r = n - 1;
        while (s[l] == s[r]) {
            if (r == l) return 1;
            int cl = l, cr = r;
            cl++, cr--;
            while (cl <= r && s[cl] == s[l]) cl++;
            while (cr >= l && s[cr] == s[r]) cr--;
            if (cl > cr) {
                return 0;
            }
            l = cl, r = cr;
        }
        return r - l + 1;
    }
};