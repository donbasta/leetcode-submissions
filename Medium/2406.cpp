class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            swap(intervals[i][0], intervals[i][1]);
        }
        sort(intervals.begin(), intervals.end());
        // sort(intervals.begin(), intervals.end(), [&](auto x, auto y) -> bool {
        //     return x[1] < y[1];
        // });
        multiset<int> rightEnds;
        for (int i = 0; i < n; i++) {
            if (!rightEnds.empty()) {
                auto bruh = rightEnds.lower_bound(intervals[i][1]);
                if (bruh != rightEnds.begin()) {
                    --bruh;
                    rightEnds.erase(bruh);
                }
            }
            rightEnds.insert(intervals[i][0]);
        }
        return rightEnds.size();
    }
};