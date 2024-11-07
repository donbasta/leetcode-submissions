class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        int in[n], vis[n], mx[n];
        memset(in, 0, sizeof(in));
        memset(vis, -1, sizeof(vis));
        memset(mx, 0, sizeof(mx));
        bool cyc[n], cyc2[n];
        memset(cyc, 0, sizeof(cyc));
        memset(cyc2, 0, sizeof(cyc2));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            in[favorite[i]]++;
            if (favorite[favorite[i]] == i) {
                cyc2[i] = true;
            }
        }
        for (int i = 0; i < n; i++) {
            if (vis[i] != -1) continue;
            int cur = i;
            vis[cur] = i;
            cur = favorite[cur];
            while (vis[cur] == -1) {
                vis[cur] = i;
                cur = favorite[cur];
            }
            if (vis[cur] == i) {
                int start = cur;
                int len_cyc = 1;
                cyc[cur] = true;
                cur = favorite[cur];
                while (cur != start) {
                    cyc[cur] = true;
                    len_cyc++;
                    cur = favorite[cur];
                }
                ans = max(ans, len_cyc);
            }
        }
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                int len = 1;
                int cur = favorite[i];
                while (!cyc[cur]) {
                    len++;
                    cur = favorite[cur];
                }
                if (cyc2[cur]) {
                    mx[cur] = max(mx[cur], len);
                }
            }
        }
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            if (!cyc2[i]) continue;
            tmp += 2 + mx[i] + mx[favorite[i]];
        }
        tmp /= 2;
        ans = max(ans, tmp);
        return ans;
    }
};