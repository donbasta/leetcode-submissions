class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        const int MX = 2000;
        vector<bool> dbl(MX + 1), ada(MX + 1);
        int n = fronts.size();
        for (int i = 0; i < n; i++) {
            if (fronts[i] == backs[i]) {
                dbl[fronts[i]] = true;
            } else {
                ada[fronts[i]] = true;
                ada[backs[i]] = true;
            }
        }
        for (int i = 1; i <= MX; i++) {
            if (!ada[i]) continue;
            if (dbl[i]) continue;
            return i;
        }
        return 0;
    }
};