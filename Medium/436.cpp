class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<vector<int>, int>> ve;
        for (int i = 0; i < n; i++) {
            ve.emplace_back(intervals[i], i);
        }
        sort(ve.begin(), ve.end());
        vector<int> ret(n, -1);
        for (int i = 0; i < n; i++) {
            int ed = ve[i].first[1];
            int idx = lower_bound(ve.begin(), ve.end(), make_pair(vector<int>{ed, ed}, -1)) - ve.begin();
            if (idx < n) {
                ret[ve[i].second] = ve[idx].second;
            }
        }
        return ret;
    }
};