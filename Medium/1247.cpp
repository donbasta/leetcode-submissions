class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.length();
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[i]) continue;
            if (s1[i] == 'x') a++;
            else b++;
        }
        if ((a % 2) != (b % 2)) return -1;
        if (a % 2 == 0) {
            return (a / 2) + (b / 2);
        }
        return (a / 2) + (b / 2) + 2;
    }
};