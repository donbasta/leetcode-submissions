class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int, int> mp, cnt;
        for (auto e : nums) {
            cnt[e]++;
            mp[e - k]++;
            mp[e + k + 1]--;
        }
        vector<pair<int, int>> ve, itv;
        for (auto e : cnt) {
            ve.emplace_back(e.first, e.second);
        }
        int sz = ve.size();
        const int INF = 2e9;
        int prv = -INF;
        int itr = 0;
        for (auto e : mp) {
            mp[e.first] += mp[prv];
            prv = e.first;
        }
        for (auto e : mp) {
            itv.emplace_back(e.first, e.second);
        }

        int l = 0, r = 0;
        int ans = 0;
        for (int i = 0; i < (int)itv.size() - 1; i++) {
            int from = itv[i].first;
            int to = itv[i + 1].first - 1;
            int tot = itv[i].second;
            while (l < sz && ve[l].first < from) l++;
            while (r < sz && ve[r].first <= to) r++;
            ans = max(ans, min(tot, numOperations));
            for (int x = l; x < r; x++) {
                int tmp = ve[x].second + min(numOperations, tot - ve[x].second);
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};