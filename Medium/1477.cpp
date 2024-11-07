class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int cur = 0;
        unordered_map<int, int> ump;
        ump[0] = 0;
        int n = arr.size();
        vector<pair<int, int>> itv, itv2;
        for (int i = 1; i <= n; i++) {
            cur += arr[i - 1];
            if (ump.count(cur - target)) {
                itv.emplace_back(ump[cur - target] + 1, i);
            }
            ump[cur] = i;
        }

        int ans = INT_MAX;
        int sz = itv.size();
        itv2 = itv;
        if (sz <= 1) return -1;
        sort(itv.begin(), itv.end());
        sort(itv2.begin(), itv2.end(), [&](pair<int, int> a, pair<int, int> b) -> bool {
            return a.second < b.second;
        });
        
        vector<int> suf(sz);
        suf[sz - 1] = itv.back().second - itv.back().first + 1;
        for (int i = sz - 2; i >= 0; i--) {
            suf[i] = min(suf[i + 1], itv[i].second - itv[i].first + 1);
        }

        int mn = INT_MAX;
        for (int i = 0; i < sz; i++) {
            mn = min(mn, itv2[i].second - itv2[i].first + 1);
            int r = lower_bound(itv.begin(), itv.end(), make_pair(itv2[i].second + 1, -1)) - itv.begin();
            if (r >= sz) continue;
            ans = min(ans, mn + suf[r]);
        }

        if (ans == INT_MAX) return -1;
        return ans;
    }
};