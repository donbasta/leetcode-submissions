class Solution {
public:
    int getKth(int lo, int hi, int k) {
        unordered_map<int, int> dp;

        const function<int(int)> getFunc = [&](int v) -> int {
            if (v == 1) return dp[1] = 0;
            if (dp.find(v) != dp.end()) {
                return dp[v];
            }
            if (v & 1) return dp[v] = (1 + getFunc(3 * v + 1));
            else return dp[v] = 1 + getFunc(v / 2);
        };

        vector<pair<int, int>> ve;
        for (int i = lo; i <= hi; i++) {
            ve.emplace_back(getFunc(i), i);
        }
        sort(ve.begin(), ve.end());
        return ve[k - 1].second;
    }
};