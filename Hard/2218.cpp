class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        const int INF = 2e9;
        vector<int> tot(k + 1, -INF);
        tot[0] = 0;
        for (int i = 1; i <= min(k, (int) piles[0].size()); i++) {
            tot[i] = tot[i - 1] + piles[0][i - 1];
        }
        for (int i = 1; i < n; i++) {
            vector<int> ntot(k + 1);
            vector<int> pref;
            pref.push_back(0);
            int tmp = 0;
            for (auto e : piles[i]) {
                tmp += e;
                pref.push_back(tmp);
            }
            for (int j = 1; j <= k; j++) {
                for (int l = 0; l <= j; l++) {
                    if (j - l >= pref.size()) continue;
                    ntot[j] = max(ntot[j], tot[l] + pref[j - l]);
                }
            }
            tot = ntot;
        }
        return tot[k];
    }
};