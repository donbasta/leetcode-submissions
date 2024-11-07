class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> cap(n + 5);
        for (auto b : bookings) {
            cap[b[0] - 1] += b[2];
            cap[b[1]] -= b[2];
        }
        vector<int> ret(n);
        ret[0] = cap[0];
        for (int i = 1; i < n; i++) {
            ret[i] = ret[i - 1] + cap[i];
        }
        return ret;
    }
};