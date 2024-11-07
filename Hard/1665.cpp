class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](vector<int> A, vector<int> B) -> bool {
            return A[1] - A[0] > B[1] - B[0];
        });
        int cur = 0;
        int n = tasks.size();
        for (int i = n - 1; i >= 0; i--) {
            cur += tasks[i][0];
            cur = max(cur, tasks[i][1]);
        }
        return cur;
    }
};