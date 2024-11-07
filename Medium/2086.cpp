class Solution {
public:
    int minimumBuckets(string s) {
        if (s == "H") return -1;
        if (s == ".") return 0;
        if (s == "HH") return -1;
        if (s == "H." || s == ".H") return 1;
        if (s == "..") return 0;
        int n = s.size();
        for (int i = 1; i < n - 1; i++) {
            if (s.substr(i - 1, 3) == "HHH") return -1;
        }

        for (int i = 0; i < n; i++) {
            if (s[i] == 'H') {
                if (i < n - 1 && s[i + 1] == 'H') {
                    if (i == 0 || i == n - 2) return -1;
                    s[i - 1] = 'X';
                    s[i + 2] = 'X';
                } else {
                    if (i > 0 && s[i - 1] == 'X') continue;
                    if (i + 1 < n) s[i + 1] = 'X';
                    else s[i - 1] = 'X';
                }
            }
        }
        return count(s.begin(), s.end(), 'X');
    }
};