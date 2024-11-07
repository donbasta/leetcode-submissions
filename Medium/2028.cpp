class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int cur_tot = accumulate(rolls.begin(), rolls.end(), 0);
        int tot = mean * (n + m);
        // n <= tot-cur_tot <= 6n
        int need = tot - cur_tot;

        vector<int> ret;
        if (need < n || need > 6 * n) {
            return ret;
        }
        int avg = need / n;
        int extra = need % n;
        ret.assign(n, avg);
        for (int i = 0; i < extra; i++) {
            ret[i]++;
        }
        return ret;
    }
};