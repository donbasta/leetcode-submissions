class Solution {
public:
    bool validPalindrome(string s) {
        string cs = s;
        reverse(cs.begin(), cs.end());
        int n = s.size();
        int l = 0;
        while (l < n && s[l] == cs[l]) l++;
        if (l == n) return true;
        int r = n - 1 - l;
        //either s[l .. r - 1] or s[l + 1 .. r] palindrome

        auto pal = [&](int i, int j) -> bool {
            int x = i, y = j;
            while (x <= y) {
                if (s[x] != s[y]) return false;
                x++, y--;
            }
            return true;
        };

        if (pal(l, r - 1) || pal(l + 1, r)) return true;
        return false;
    }
};