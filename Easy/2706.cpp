class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int tot = prices[0] + prices[1];
        if (tot > money) return money;
        return money - tot;
    }
};