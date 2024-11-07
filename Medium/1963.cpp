class Solution {
public:
    int minSwaps(string s) {
        int n = s.length();
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '[') tmp++;
            else if (tmp > 0) tmp--;
        }
        return (tmp + 1) / 2;
    }
};