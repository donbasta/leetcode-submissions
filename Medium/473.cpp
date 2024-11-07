class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int K = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (K % 4 != 0) return false;
        int S = K / 4;
        vector<int> V;
        for (int i = 0; i < (1 << n); i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                if (!((i >> j) & 1)) continue;
                tmp += matchsticks[j];
                if (tmp > S) break;
            }
            if (tmp == S) {
                V.push_back(i);
            }
        }
        int sz = V.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((V[i] & V[j]) > 0) continue;
                for (int k = j + 1; k < sz; k++) {
                    if (((V[i] & V[k]) > 0) || ((V[j] & V[k]) > 0)) continue;
                    return true;
                }
            }
        }
        return false;
    }
};