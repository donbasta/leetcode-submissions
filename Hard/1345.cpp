class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;
        if (n == 2 || arr[0] == arr.back()) return 1;
 
        vector<int> cnt = arr;
        sort(cnt.begin(), cnt.end());
        cnt.resize(unique(cnt.begin(), cnt.end()) - cnt.begin());

        unordered_map<int, int> ump;
        int idx = n;
        for (auto e : cnt) ump[e] = idx++;

        vector<vector<pair<int, int>>> adj(idx);
        for (int i = 0; i < n; i++) {
            int cur_val = ump[arr[i]];
            if (i > 0) {
                adj[i].emplace_back(i - 1, 1);
            }
            if (i < n - 1) {
                adj[i].emplace_back(i + 1, 1);
            }
            adj[i].emplace_back(cur_val, 1);
            adj[cur_val].emplace_back(i, 0);
        }

        const int INF = 2e9;
        vector<int> dis(idx, INF);

        deque<int> Q;
        Q.push_front(0);
        dis[0] = 0;
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop_front();
            for (auto c : adj[now]) {
                int u = c.first, v = c.second;
                if (dis[now] + v < dis[u]) {
                    dis[u] = dis[now] + v;
                    if (v == 1) {
                        Q.push_back(u);
                    } else if (v == 0) {
                        Q.push_front(u);
                    }
                }
            }
        }
        return dis[n - 1];
    }
};