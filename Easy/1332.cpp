class Solution {
public:
    int removePalindromeSub(string s) {
        string c = s;
        reverse(c.begin(), c.end());
        return 1 + (c != s);
    }
};