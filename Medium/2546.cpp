class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int n = s.length();
        string cek(n, '0');
        if (s == cek && target == cek) return true;
        if (s == cek || target == cek) return false;
        return true;
    }
};