class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int kur = 0;
            for (int j = i + 1; j < n; j++) {
                if (prices[j] <= prices[i]) {
                    kur = prices[j];
                    break;
                }
            }
            ans[i] = prices[i] - kur;
        }
        return ans;
    }
};