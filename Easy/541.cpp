class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        for (int i = 0; i < n; i += k * 2) {
            int l = i, r = min(n - 1, i + k - 1);
            while (l < r) {
                swap(s[l], s[r]);
                l++, r--;
            }
        }
        return s;
    }
};