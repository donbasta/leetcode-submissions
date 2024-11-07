class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lost;
        for (auto e : matches) {
            if (!lost.count(e[0])) lost[e[0]] = 0;
            lost[e[1]]++;
        }
        vector<vector<int>> ret(2);
        for (auto e : lost) {
            if (e.second == 0) ret[0].push_back(e.first);
            else if (e.second == 1) ret[1].push_back(e.first);
        }
        for (int i = 0; i < 2; i++) {
            sort(ret[i].begin(), ret[i].end());
        }
        return ret;
    }
};