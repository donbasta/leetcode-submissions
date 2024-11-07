class Solution {
public:
    int flipLights(int n, int presses) {
        set<vector<bool>> se;
        for (int mask = 0; mask < (1 << 4); mask++) {
            int byk = __builtin_popcount(mask);
            bool can = (byk % 2 == presses % 2 && byk <= presses);
            if (!can) continue;
            vector<bool> tmp(n);
            if ((mask >> 0) & 1) {
                for (int i = 0; i < n; i++) tmp[i] = !tmp[i];
            }
            if ((mask >> 1) & 1) {
                for (int i = 1; i < n; i += 2) tmp[i] = !tmp[i];
            }
            if ((mask >> 2) & 1) {
                for (int i = 0; i < n; i += 2) tmp[i] = !tmp[i];
            }
            if ((mask >> 3) & 1) {
                for (int i = 0; i < n; i += 3) tmp[i] = !tmp[i];
            }
            se.insert(tmp);
        }
        return (int)se.size();
    }
};