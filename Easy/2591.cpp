class Solution {
public:
    int distMoney(int money, int children) {
        // x <= children
        // 8x <= money
        // money - 8x >= children - x
        // money - children >= 7x

        if (money < children) return -1;
        int x = min({children, money / 8, (money - children) / 7});
        if (x == children) {
            if (money > 8 * x) return children - 1;
            return children;
        }
        if (x == children - 1) {
            if (money == 8 * x + 4) return children - 2;
            return children - 1;
        }
        return x;
    }
};