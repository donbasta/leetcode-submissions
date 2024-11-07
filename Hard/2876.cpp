class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> cnt(n), col(n, -1);
        vector<bool> vis(n);
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            int cur = i;
            vector<int> tmp;
            while (!vis[cur]) {
                col[cur] = i;
                vis[cur] = true;
                tmp.push_back(cur);
                cur = edges[cur];
            }
            // cout << tmp.size() << '\n';
            int sz = tmp.size();
            if (col[cur] == i) {
                bool in_cycle = false;
                int x = sz;
                for (int i = 0; i < sz; i++) {
                    if (in_cycle) {
                        cnt[tmp[i]] = x;
                    } else if (tmp[i] == cur) {
                        in_cycle = true;
                        cnt[tmp[i]] = x;
                    } else {
                        cnt[tmp[i]] = x--;
                    }
                }
            } else {
                reverse(tmp.begin(), tmp.end());
                int lol = cnt[cur];
                for (auto x : tmp) {
                    cnt[x] = ++lol;
                }
            }
        }
        return cnt;
    }
};