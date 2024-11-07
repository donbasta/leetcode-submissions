class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        vector<int> ve(n);
        int prv = 0;
        for (auto l : logs) {
            ve[l[0]] = max(ve[l[0]], l[1] - prv);
            prv = l[1];
        }
        int id = 0, mx = ve[0];
        for (int i = 1; i < n; i++) {
            if (ve[i] > mx) {
                mx = ve[i];
                id = i;
            }
        }
        return id;
    }
};