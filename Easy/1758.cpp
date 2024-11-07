class Solution {
public:
    int minOperations(string s) {
        int ch[2];
        ch[0] = ch[1] = 0;
        for (int i = 0; i < 2; i++) {
            int cur = i;
            for (auto c : s) {
                ch[i] += (c - '0' != cur);
                cur ^= 1;
            }
        }
        return min(ch[0], ch[1]);
    }
};