class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        purchaseAmount = 10 * ((purchaseAmount + 5) / 10);
        return 100 - purchaseAmount;
    }
};