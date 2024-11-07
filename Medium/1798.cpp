class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int cur = 0;
        int n = coins.size();
        for (int i = 0; i < n; i++) {
            if (coins[i] > cur + 1) {
                return cur + 1;
            }
            cur += coins[i];
        }
        return cur + 1;
    }
};