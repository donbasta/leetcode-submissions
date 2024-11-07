class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int x = __gcd(jug1Capacity, jug2Capacity);
        return (targetCapacity <= (jug1Capacity + jug2Capacity)) && (targetCapacity % x == 0);
    }
};