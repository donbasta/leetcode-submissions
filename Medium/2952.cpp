class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        long long cur = 0;
        int ret = 0;
        for (int i = 0; i < n; i++) {
            while (coins[i] > cur + 1) {
                ret++;
                cur += (cur + 1);
                if (cur >= target) return ret;
            }
            cur += coins[i];
            if (cur >= target) return ret;

        }
        while (target > cur) {
            cur += (cur + 1);
            ret++;
        }
        return ret;
    }
};