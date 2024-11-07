class Solution {
public:
    int countDigits(int num) {
        int cp = num;
        int ans = 0;
        while (num) {
            int d = (num % 10);
            ans += cp % d == 0;
            num /= 10;
        }
        return ans;
    }
};