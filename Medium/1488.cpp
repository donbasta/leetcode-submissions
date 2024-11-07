class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans, nx(n, n);
        map<int, int> mp;

        for (int i = n - 1; i >= 0; i--) {
            if (mp.count(rains[i])) {
                nx[i] = mp[rains[i]];
            }
            mp[rains[i]] = i;
        }

        set<pair<int, int>> s1; //next_idx, lake_pos
        set<int> s2; //lake_pos
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                if (!s1.empty()) {
                    ans.push_back(s1.begin()->second);
                    s2.erase(s1.begin()->second);
                    s1.erase(s1.begin());
                } else {
                    ans.push_back(1);
                }
            } else {
                if (s2.count(rains[i])) {
                    ans.clear();
                    return ans;
                } else {
                    s2.insert(rains[i]);
                    s1.emplace(nx[i], rains[i]);
                }
                ans.push_back(-1);
            }
        }

        return ans;
    }
};