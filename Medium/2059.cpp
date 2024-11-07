class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        vector<vector<int>> from(1001);
        const int INF = 2e9;
        vector<int> D(1001, INF);
        vector<bool> vis(1001);
        for (int i = 0; i <= 1000; i++) {
            for (auto n : nums) {
                if ((i + n <= 1000) && (i + n >= 0)) from[i].push_back(i + n);
                if ((i - n >= 0) && (i - n <= 1000)) from[i].push_back(i - n);
                if (((i ^ n) >= 0) && ((i ^ n) <= 1000)) from[i].push_back(i ^ n);
            }
        }
        for (int i = 0; i <= 1000; i++) {
            sort(from[i].begin(), from[i].end());
            from[i].resize(unique(from[i].begin(), from[i].end()) - from[i].begin());
        }
        queue<int> Q;
        Q.push(start);
        vis[start] = true;
        D[start] = 0;
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            for (auto nx : from[now]) {
                if (vis[nx]) continue;
                // if (nx < 0 || nx > 1000) {
                //     cout << nx << '\n';
                // }
                D[nx] = D[now] + 1;
                vis[nx] = true;
                Q.push(nx);
            }
        }
        if (0 <= goal && goal <= 1000) {
            if (D[goal] == INF) return -1;
            return D[goal];
        }
        int ans = INF;
        for (auto n : nums) {
            if (n + goal >= 0 && n + goal <= 1000) {
                ans = min(ans, 1 + D[n + goal]);
            }
            if (goal - n >= 0 && goal - n <= 1000) {
                ans = min(ans, 1 + D[goal - n]);
            }
            if ((n ^ goal) >= 0 && (n ^ goal) <= 1000) {
                ans = min(ans, 1 + D[n ^ goal]);
            }
        }
        if (ans == INF) return -1;
        return ans;
    }
};