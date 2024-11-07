class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0, full = numBottles, empty = 0;
        while (true) {
            ans += full;
            empty += full;
            full = 0;
            if (empty < numExchange) {
                break;
            }
            while (empty >= numExchange) {
                empty -= numExchange;
                full++;
                numExchange++;
            }
        }
        return ans;
    }
};