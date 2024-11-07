class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int n = s.length();
        unordered_map<int, pair<int, int>> ump;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 1; (j < 32) && (i + j - 1 < n); j++) {
                cur *= 2;
                cur += (s[i + j - 1] - '0');
                if (ump.find(cur) == ump.end()) {
                    ump[cur] = make_pair(i, i + j - 1);
                } else {
                    if (ump[cur].second - ump[cur].first > j - 1) {
                        ump[cur] = make_pair(i, i + j - 1);
                    }
                }
            }
        }
        vector<vector<int>> ret;
        for (auto q : queries) {
            int left = q[0], right = q[1];
            int need = left ^ right;
            if (ump.find(need) == ump.end()) {
                ret.push_back({-1, -1});
            } else {
                ret.push_back({ump[need].first, ump[need].second});
            }
        }
        return ret;
    }
};