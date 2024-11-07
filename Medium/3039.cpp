class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<vector<int>> pos(26);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            pos[s[i] - 'a'].push_back(i);
        }
        int mx = -1;
        for (int i = 0; i < 26; i++) {
            mx = max(mx, (int)pos[i].size());
        }
        vector<pair<int, int>> ve;
        for (int i = 0; i < 26; i++) {
            if ((int)pos[i].size() == mx) ve.emplace_back(pos[i].back(), i);
        }
        sort(ve.begin(), ve.end());
        string ret;
        for (auto e : ve) {
            ret += (char)(e.second + 'a');
        }
        return ret;
    }
};