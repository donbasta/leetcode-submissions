class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        sort(items.begin(), items.end());
        vector<int> mx_pref(n);
        mx_pref[0] = items[0][1];
        for (int i = 1; i < n; i++) {
            mx_pref[i] = max(mx_pref[i - 1], items[i][1]);
        }
        vector<int> ret;
        for (auto q : queries) {
            int t = upper_bound(items.begin(), items.end(), vector<int>{q, INT_MAX}) - items.begin();
            --t;
            if (t < 0) ret.push_back(0);
            else ret.push_back(mx_pref[t]);
        }
        return ret;
    }
};