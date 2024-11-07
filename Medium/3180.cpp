class Solution {
public:
    int maxTotalReward(vector<int>& val) {
        int n = val.size();
        sort(val.begin(), val.end());
        int M = 4 * val.back();

        vector<bool> can(M + 5);
        can[0] = true;
        can[val[0]] = true;
        for (int i = 0; i < n; i++) {
            for (int j = 2 * val[i] - 1; j >= val[i]; j--) {
                if (can[j - val[i]]) can[j] = true;
            }
        }
        for (int i = M; i >= 0; i--) {
            if (can[i]) return i;
        }
        return -1;
    }
};