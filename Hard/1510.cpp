class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> xixi(n + 1);
        xixi[1] = true;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                if (!xixi[i - j * j]) {
                    xixi[i] = true;
                    break;
                }
            }
        }
        return xixi[n];
    }
};