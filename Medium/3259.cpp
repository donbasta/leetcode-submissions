class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        using ll = long long;
        int n = energyDrinkA.size();
        ll dp[n][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = energyDrinkA[0];
        dp[0][1] = energyDrinkB[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0] + energyDrinkA[i], dp[i - 1][1]);
            dp[i][1] = max(dp[i - 1][1] + energyDrinkB[i], dp[i - 1][0]);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};