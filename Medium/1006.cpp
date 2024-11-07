class Solution {
public:
    int clumsy(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        } else if (n == 3) {
            return 6;
        }
        int ans = n * (n - 1) / (n - 2) + (n - 3);
        int lmao;
        if (n - 4 < 4) {
            lmao = clumsy(n - 4);
        } else {
            lmao = (n - 4) * (n - 5) / (n - 6);
        }
        return ans + clumsy(n - 4) - 2 * lmao;
    }
};