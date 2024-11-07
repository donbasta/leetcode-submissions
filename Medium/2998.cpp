class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if (x == y) {
            return 0;
        }
        vector<bool> vis(20000);
        queue<int> Q;
        const int INF = 1e9;
        vector<int> dis(20000, INF);
        Q.push(x);
        dis[x] = 0;
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            if (now % 5 == 0) {
                int nw = now / 5;
                if (!vis[nw]) {
                    vis[nw] = true;
                    dis[nw] = dis[now] + 1;
                    Q.push(nw);
                    if (nw == y) return dis[nw];
                }
            }
            if (now % 11 == 0) {
                int nw = now / 11;
                if (!vis[nw]) {
                    vis[nw] = true;
                    dis[nw] = dis[now] + 1;
                    Q.push(nw);
                    if (nw == y) return dis[nw];
                }
            }
            for (auto nw : {now + 1, now - 1}) {
                if (nw <= 0) continue;
                if (vis[nw]) continue;
                vis[nw] = true;
                dis[nw] = dis[now] + 1;
                Q.push(nw);
                if (nw == y) return dis[nw];
            }
        }
        return -1;
    }
};