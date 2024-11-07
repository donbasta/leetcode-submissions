class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        const int INF = 1e9;
        vector<int> in(n), least(n, INF), idx(n, -1);
        vector<vector<int>> from(n);

        for (auto r : richer) {
            from[r[0]].push_back(r[1]);
            in[r[1]]++;
        }
        queue<int> Q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                Q.emplace(i);
            }
        }
        while (!Q.empty()) {
            int now = Q.front();
            Q.pop();
            if (least[now] > quiet[now]) {
                least[now] = quiet[now];
                idx[now] = now;
            }
            for (auto f : from[now]) {
                if (least[f] > least[now]) {
                    least[f] = least[now];
                    idx[f] = idx[now];
                }
                --in[f];
                if (in[f] == 0) {
                    Q.push(f);
                }
            }
        }
        return idx;
    }
};