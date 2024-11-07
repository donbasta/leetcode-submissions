class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(), m = worker.size();
        const int M = 1e5;
        vector<int> pref(M + 1), best(M + 1);
        for (int i = 0; i < n; i++) {
            best[difficulty[i]] = max(best[difficulty[i]], profit[i]);
        }
        for (int i = 1; i <= M; i++) {
            pref[i] = max(pref[i - 1], best[i]);
        }
        int ret = 0;
        for (int i = 0; i < m; i++) {
            ret += pref[worker[i]];
        }
        return ret;
    }
};