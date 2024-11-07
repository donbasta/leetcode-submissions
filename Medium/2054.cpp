class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [&](vector<int> a, vector<int> b) -> bool {
            return a[1] < b[1];
        });
        int n = events.size();
        vector<int> mx(n), rights(n);
        for (int i = 0; i < n; i++) rights[i] = events[i][1];
        int ret = events[0][2];
        mx[0] = events[0][2];
        for (int i = 1; i < n; i++) {
            ret = max(ret, events[i][2]);
            int k = lower_bound(rights.begin(), rights.end(), events[i][0]) - rights.begin();
            k--;
            if (k >= 0) ret = max(ret, events[i][2] + mx[k]);
            mx[i] = max(mx[i - 1], events[i][2]);
        }
        return ret;
    }
};