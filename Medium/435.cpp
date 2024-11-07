class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [&](const vector<int>& a, const vector<int>& b) -> bool {
            if (a[1] == b[1]) {
                return a[0] < b[0];
            }
            return a[1] < b[1];
        });
        int size = 1;
        int r = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= r) {
                size++;
                r = intervals[i][1];
            }
        }
        return n - size;
    }
};