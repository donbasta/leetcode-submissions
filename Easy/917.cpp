class Solution {
public:
    string reverseOnlyLetters(string s) {
        const function<bool(char)> check = [&](char c) -> bool {
            return (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')));
        };
        int n = s.length();
        int i = 0, j = n - 1;
        while (i < j) {
            while ((i < n) && !check(s[i])) i++;
            while ((j >= 0) && !check(s[j])) j--;
            if (i < j) {
                swap(s[i], s[j]);
                i++, j--;
            }
        }
        return s;
    }
};