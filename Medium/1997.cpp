class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        // f[0] = 0;
        // f[1] = 2;
        // ...
        // f[i]
        // f[i + 1] = 2 * f[i] + 1 - f[nextVisit[i]] + 1
        int n = nextVisit.size();
        vector<int> ve(n);
        ve[0] = 0;
        const int MOD = 1e9 + 7;
        for (int i = 1; i < n; i++) {
            ve[i] = ((ve[i - 1] * 2) + 2 - ve[nextVisit[i - 1]]) % MOD;
            if (ve[i] < 0) ve[i] += MOD;
        } 
        int ret = ve.back() % MOD;
        if (ret < 0) ret += MOD;
        return ret;
    }
};