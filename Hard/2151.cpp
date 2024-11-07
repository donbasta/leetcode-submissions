class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int ans = 0;
        for (int i = 0; i < (1 << n); i++) {
            bool tmp = true;
            for (int j = 0; j < n; j++) {
                if (!((i >> j) & 1)) {
                    continue;
                }
                for (int k = 0; k < n; k++) {
                    if (k == j) continue;
                    int good = (i >> k) & 1;
                    int stmt = statements[j][k];
                    if ((good && (stmt == 0)) || (!good && (stmt == 1))) {
                        tmp = false;
                        break;
                    }
                }
                if (!tmp) break;
            }
            if (tmp) {
                ans = max(ans, __builtin_popcount(i));
            }
        }
        return ans;
    }
};