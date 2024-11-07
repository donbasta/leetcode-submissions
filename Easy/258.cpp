class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        int ans = num % 9;
        if (ans == 0) ans = 9;
        return ans;
    }
};