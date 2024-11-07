class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        using ll = long long;
        ll last = 0;
        int n = customers.size();
        ll tot = 0;
        for (int i = 0; i < n; i++) {
            if (last < 1ll * customers[i][0]) {
                last = 1ll * customers[i][0] + customers[i][1];
            } else {
                tot += last - customers[i][0];
                last += customers[i][1];
            }
            tot += customers[i][1];
        }
        return ((double)tot) / n;
    }
};