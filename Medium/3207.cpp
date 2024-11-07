class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        using ll = long long;
        sort(enemyEnergies.begin(), enemyEnergies.end());
        ll cur = currentEnergy;
        if (cur < 1ll * enemyEnergies[0]) {
            return 0;
        }
        ll tot = cur - enemyEnergies[0];
        for (auto e : enemyEnergies) {
            tot += e;
        }
        return (tot / enemyEnergies[0]);
    }
};