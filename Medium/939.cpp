class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, vector<int>> ver, hori;
        set<pair<int, int>> se;
        for (auto e : points) {
            ver[e[0]].push_back(e[1]);
            hori[e[1]].push_back(e[0]);
            se.emplace(e[0], e[1]);
        }
        int ans = INT_MAX;
        for (auto e : points) {
            for (auto p : ver[e[0]]) {
                if (p == e[1]) continue;
                for (auto q : hori[e[1]]) {
                    if (q == e[0]) continue;
                    if (se.count(make_pair(q, p))) {
                        ans = min(ans, abs(q - e[0]) * abs(p - e[1]));
                    }
                }
            }
        }
        if (ans == INT_MAX) return 0;
        return ans;
    }
};