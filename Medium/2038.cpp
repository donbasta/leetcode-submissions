class Solution {
public:
    bool winnerOfGame(string colors) {
        int len = 1;
        char cur = colors[0];
        int n = colors.length();
        int A = 0, B = 0;
        for (int i = 1; i < n; i++) {
            if (colors[i] == cur) {
                len++;
            } else {
                if (cur == 'A') {
                    A += max(len - 2, 0);
                } else {
                    B += max(len - 2, 0);
                }
                len = 1;
                cur = colors[i];
            }
        }
        if (cur == 'A') {
            A += max(len - 2, 0);
        } else {
            B += max(len - 2, 0);
        }
        return A > B;
    }
};