class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int c1 = 0, c2 = 0, s1 = 0, s2 = 0;
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') c1++;
            else s1 += (num[i] - '0');
        }
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') c2++;
            else s2 += (num[i] - '0');
        }
        s1 += 9 * (c1 / 2);
        s2 += 9 * (c2 / 2);
        return !((s1 == s2) && ((c1 % 2) == (c2 % 2)));
    }
};