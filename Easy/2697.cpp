class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] == s[n - 1 - i]) continue;
            char x = min(s[i], s[n - 1 - i]);
            s[i] = s[n - 1 - i] = x;
        }
        return s;
    }
};