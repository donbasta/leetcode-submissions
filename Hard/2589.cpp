class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](vector<int>& A, vector<int>& B) -> bool {
            return A[1] < B[1];
        });
        const int M = 2000;
        vector<bool> on(M + 1);
        int n = tasks.size();
        for (int i = 0; i < n; i++) {
            int need = tasks[i][2];
            int S = tasks[i][0], E = tasks[i][1];
            for (int j = S; j <= E; j++) {
                need -= on[j];
            }
            if (need > 0) {
                for (int j = E; j >= S; j--) {
                    if (on[j]) continue;
                    on[j] = true;
                    --need;
                    if (need == 0) break;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= M; i++) ans += on[i];
        return ans;
    }
};