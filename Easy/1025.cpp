class Solution {
public:
    bool divisorGame(int n) {
        bool w[n + 5];
        memset(w, false, sizeof(w));
        w[2] = true;
        w[3] = false;
        for (int i = 4; i <= n; i++) {
            bool win = false;
            for (int j = 1; j * j <= n; j++) {
                if (i % j != 0) continue;
                if (!w[i - j]) {
                    win = true;
                }
                if (j != 1 && !w[i - (i / j)]) {
                    win = true;
                }
                if (win) break;
            }
            w[i] = win;
        }
        return w[n];
    }
};