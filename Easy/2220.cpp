class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        int B = 30;
        for (int i = 0; i < B; i++) {
            ans += ((start >> i) & 1) != ((goal >> i) & 1);
        }
        return ans;
    }
};