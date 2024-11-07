class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int emp = 0;
        int ret = 0;
        int full = numBottles;
        while (full > 0) {
            ret += full;
            emp += full;
            full = emp / numExchange;
            emp %= numExchange;
        }
        return ret;
    }
};