class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        using ll = long long;
        vector<ll> ret(n);
        for (auto e : mp) {
            // vector<int> ve = e.second;
            int sz = e.second.size();
            if (sz == 1) continue;
            ll tot = accumulate(e.second.begin(), e.second.end(), 0ll);
            ll cur = 0;
            int idx = 0;
            for (auto ee : e.second) {
                ret[ee] = tot - cur * 2 + 1ll * ee * (idx * 2 - sz);
                idx++;
                cur += ee;
            }
        }
        return ret;
    }
};