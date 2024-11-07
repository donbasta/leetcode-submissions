class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if (n == 1) return 1;
 
        double cum = 0;
        double cur = 0;
        for (int i = n - 1; i >= 1; i--) {
            cur = ((double)1 + cum) / (n - i + 1);
            cum += cur;
        }
        return cur;
    }
};