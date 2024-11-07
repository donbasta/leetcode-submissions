class Solution {
public:
    bool isPalindrome(int x) {
        string t = to_string(x);
        string s = t;
        reverse(s.begin(), s.end());
        return (s == t);
    }
};