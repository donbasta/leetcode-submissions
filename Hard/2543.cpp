class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        int lmao = __gcd(targetX, targetY);
        while (lmao % 2 == 0) {
            lmao /= 2;
        }
        return lmao == 1;
    }
};