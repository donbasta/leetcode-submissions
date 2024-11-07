class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0, cx = x;
        while (cx) {
            sum += cx % 10;
            cx /= 10;
        }
        if (x % sum != 0) return -1;
        return sum;
    }
};