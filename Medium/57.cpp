class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        int start = newInterval[0], end = newInterval[1];
        bool found = false;
        for (int i = 0; i < intervals.size(); i++) {
            if ((intervals[i][1] < newInterval[0]) || (intervals[i][0] > newInterval[1])) {
                ret.push_back(intervals[i]);
                continue;
            }
            if (!found) {
                found = true, start = min(start, intervals[i][0]);
            } 
            end = max(end, intervals[i][1]);
        }
        ret.push_back(vector<int>{start, end});
        sort(ret.begin(), ret.end());
        return ret;
    }
};