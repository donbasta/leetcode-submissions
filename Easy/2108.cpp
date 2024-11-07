class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        const function<bool(const string&)> is_palindrome = [&](const string& s) -> bool {
            int n = s.length();
            for (int i = 0; i < n / 2; i++) {
                if (s[i] != s[n - 1 - i]) return false;
            }
            return true;
        };
        for (auto w : words) {
            if (is_palindrome(w)) return w;
        }
        return "";
    }
};