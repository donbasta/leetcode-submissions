class Solution {
public:
    bool isFascinating(int n) {
        int n2 = n * 2, n3 = n * 3;
        string s = to_string(n) + to_string(n2) + to_string(n3);
        sort(s.begin(), s.end());
        if (s.length() != 9) return false;
        for (int i = 0; i < 9; i++) {
            if (s[i] - '1' != i) return false;
        }
        return true;
    }
};