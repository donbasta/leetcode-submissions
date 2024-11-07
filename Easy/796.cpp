class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        if (goal.length() != n) return false;
        for (int i = 0; i < n; i++) {
            int st = i;
            bool ok = true;
            for (int j = 0; j < n; j++) {
                if (s[j] != goal[st]) {
                    ok = false;
                    break;
                }
                st = (st + 1) % n;
            }
            if (ok) return true;
        }
        return false;
    }
};