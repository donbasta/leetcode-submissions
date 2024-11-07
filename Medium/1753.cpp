class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int x = max({a, b, c});
        int z = min({a, b, c});
        int y = a + b + c - x - z;
        return min(y + z, (x + y + z) / 2);
    }
};