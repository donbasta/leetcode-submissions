class Solution {
public:
    bool isPalindrome(string s) {
        const function<bool(char)> is_lower = [&](char c) -> bool {
            return (c >= 'a') && (c <= 'z');
        };
        const function<bool(char)> is_upper = [&](char c) -> bool {
            return (c >= 'A') && (c <= 'Z');
        };
        const function<bool(char)> is_number = [&](char c) -> bool {
            return (c >= '0') && (c <= '9');
        };
        const function<bool(char)> is_alphanumeric = [&](char c) -> bool {
            return is_lower(c) || is_upper(c) || is_number(c);
        };
        const function<char(char)> to_lower = [&](char c) -> char {
            if (is_lower(c) || is_number(c)) return c;
            return c + 'a' - 'A';
        };
        string parse;
        for (auto c : s) {
            if (is_alphanumeric(c)) {
                parse.push_back(to_lower(c));
            }
        }
        int n = parse.length();
        for (int i = 0; i < n; i++) {
            if (parse[i] != parse[n - 1 - i]) return false;
        }
        return true;
    }
};