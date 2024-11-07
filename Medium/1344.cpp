class Solution {
public:
    double angleClock(int hour, int minutes) {
        double a, b;
        if (hour == 12) hour = 0;
        b = (double)6 * minutes;
        a = (double)hour * 30 + ((double)minutes / 2);
        double T = abs(b - a);
        return min(T, (double)360 - T);
    }
};