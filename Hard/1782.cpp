using ll = long long;

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        // map<vector<int>, int> mp;
        unordered_map<int, unordered_map<int, int>> mp;
        int deg[n + 1];
        vector<int> adj[n + 1];
        memset(deg, 0, sizeof(deg));
        int m = edges.size();

        for (auto e : edges) {
            deg[e[0]]++, deg[e[1]]++;
            if (mp[e[0]][e[1]] == 0) {
                adj[e[0]].push_back(e[1]);
                adj[e[1]].push_back(e[0]);
            }
            mp[e[0]][e[1]]++;
            mp[e[1]][e[0]]++;
        }

        int cnt[m + 2], suf[m + 2];
        memset(suf, 0, sizeof(suf));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) cnt[deg[i]]++;
        for (int i = m; i >= 0; i--) {
            suf[i] = suf[i + 1] + cnt[i];
        }

        vector<int> ret(queries.size());
        int ptr = 0;
        for (auto q : queries) {
            ll tmp = 0;
            for (int i = 1; i <= n; i++) {
                int ki = max(0, q + 1 - deg[i]);
                tmp += suf[ki];
                for (auto c : adj[i]) {
                    if ((deg[i] + deg[c] > q) && (deg[i] + deg[c] - mp[i][c] <= q)) {
                        tmp--;
                    }
                }
            }
            for (int i = 1; i <= n; i++) {
                if (deg[i] * 2 > q) tmp--;
            }
            ret[ptr++] = tmp / 2;
        }
        return ret;
    }
};