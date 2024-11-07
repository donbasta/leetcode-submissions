class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> mp;
        for (auto e : access_times) {
            string tm = e[1];
            int hh = stoi(tm.substr(0, 2));
            int mm = stoi(tm.substr(2, 2));
            int t = hh * 60 + mm;
            mp[e[0]].push_back(t);
        }
        vector<string> ret;
        for (auto e : mp) {
            sort(e.second.begin(), e.second.end());
            int sz = e.second.size();
            if (sz <= 2) continue;
            bool ok = false;
            for (int i = 2; i < sz; i++) {
                if (e.second[i] - e.second[i - 2] < 60) {
                    ok = true;
                }
            }
            if (ok) {
                ret.push_back(e.first);
            }
        }
        return ret;
    }
};