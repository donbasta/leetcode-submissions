class Solution {
public:
    bool checkRecord(string s) {
        int a = 0, l = 0, cur = 0;
        for (auto c : s) {
            if (c == 'P') { cur = 0; }
            else if (c == 'A') { cur = 0; a++; }
            else if (c == 'L') {
                cur++;
                l = max(l, cur);
            }
        }
        return ((a < 2) && (l < 3));
    }
};