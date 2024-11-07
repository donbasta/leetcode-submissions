class Solution {
public:
    int maximumUnits(vector<vector<int>>& b, int t) {
        sort(b.begin(), b.end(), [&](vector<int>& x, vector<int>& y) -> bool {
            return x[1] > y[1];
        });
        int itr = 0;
        int ans = 0;
        while (itr < b.size()) {
            int take = min(t, b[itr][0]);
            t -= take;
            ans += b[itr][1] * take;
            itr++;
            if (t <= 0) break;
        }
        return ans;
    }
};