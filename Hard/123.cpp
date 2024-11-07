class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> l(n + 5), r(n + 5);
        int mn = prices[0];
        for (int i = 1; i < n; i++) {
            l[i + 1] = l[i];
            if (prices[i] > mn) {
                l[i + 1] = max(l[i + 1], prices[i] - mn);
            } else {
                mn = prices[i];
            }
        }
        int mx = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            r[i + 1] = r[i + 2];
            if (prices[i] < mx) {
                r[i + 1] = max(r[i + 1], mx - prices[i]);
            } else {
                mx = prices[i];
            }
        }
        int ans = max(r[1], l[n]);
        for (int i = 2; i <= n - 2; i++) {
            ans = max(ans, l[i] + r[i + 1]);
        }
        return ans;
    }
};