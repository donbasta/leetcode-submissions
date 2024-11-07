class Solution {
public:
    int arrangeCoins(int n) {
        int row = 0;
        long long tot = 0;
        while (tot <= 1ll * n) {
            row++, tot += row;
        }
        return row - 1;
    }
};