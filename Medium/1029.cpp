class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort (costs.begin(), costs.end(), [&](const vector<int>& x, const vector<int>& y) -> bool {
            return x[1] - x[0] < y[1] - y[0];
        });
        int tot = 0;
        int n = costs.size();
        for (int i = 0; i < (n / 2); i++) tot += costs[i][1];
        for (int i = (n / 2); i < n; i++) tot += costs[i][0];
        return tot;
    }
};