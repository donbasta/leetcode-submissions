class Solution {
public:
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
        int ce = edges.size();
        vector<int> deg(n);
        vector<vector<int>> adj(n);
        vector<bool> used(n);
        for (auto e : edges) {
            deg[e[0]]++, deg[e[1]]++;
            adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);
        }

        auto find_not_used = [&](int x) -> int {
            for (auto c : adj[x]) {
                if (used[c]) continue;
                return c;
            }
            assert(false);
            return -1;
        };

        vector<vector<int>> ans;
        if (ce == n - 1) {
            int st = -1;
            for (int i = 0; i < n; i++) {
                if (deg[i] == 1) {
                    st = i;
                    break;
                }
            }
            ans.assign(1, vector<int>(n));
            ans[0][0] = st;
            used[st] = true;
            for (int i = 1; i < n; i++) {
                ans[0][i] = find_not_used(ans[0][i - 1]);
                used[ans[0][i]] = true;
            }
        } else if (*max_element(deg.begin(), deg.end()) == 3) {
            assert (n % 2 == 0);
            ans.assign(2, vector<int>(n / 2));
            int st = -1;
            for (int i = 0; i < n; i++) {
                if (deg[i] == 2) {
                    st = i;
                    break;
                }
            }
            int st2 = -1;
            for (auto c : adj[st]) {
                if (deg[c] == 2) {
                    st2 = c;
                    break;
                }
            } 
            ans[0][0] = st; used[st] = true;
            ans[1][0] = st2; used[st2] = true;
            for (int i = 1; i < n / 2; i++) {
                ans[0][i] = find_not_used(ans[0][i - 1]);
                ans[1][i] = find_not_used(ans[1][i - 1]);
                used[ans[0][i]] = true;
                used[ans[1][i]] = true;
            }
        } else {
            int aa = 0, bb = 0, cc = 0;
            for (int i = 0; i < n; i++) {
                if (deg[i] == 2) aa++;
                else if (deg[i] == 3) bb++;
                else if (deg[i] == 4) cc++;
                else assert(false);
            }
            assert(aa == 4);
            int sum = bb / 2 + 4;
            int r = -1, c = -1;
            for (int i = 1; i * i <= n; i++) {
                if (n % i != 0) continue;
                if (i + (n / i) == sum) {
                    r = i, c = n / i;
                    break;
                }
            }
            assert (r != -1);
            int st = -1;
            ans.assign(r, vector<int>(c, -1));
            for (int i = 0; i < n; i++) {
                if (deg[i] == 2) {
                    st = i;
                    break;
                }
            }

            auto go = [&](int x, int y) -> vector<int> {
                vector<int> ret;
                ret.push_back(x);
                ret.push_back(y);
                if (deg[y] == 2) return ret;
                queue<int> Q;
                Q.push(y);
                vector<bool> vis(n);
                vis[x] = vis[y] = true;
                while (!Q.empty()) {
                    auto now = Q.front();
                    Q.pop();
                    for (auto c : adj[now]) {
                        if (deg[c] == 4) continue;
                        if (vis[c]) continue;
                        vis[c] = true;
                        Q.push(c);
                        ret.push_back(c);
                        if (deg[c] == 2) return ret;
                    }
                }
                assert (false);
                return ret;
            };

            vector<int> tmp = go(st, adj[st][0]);
            if (tmp.size() == r) {
                swap(r, c);
                ans.assign(r, vector<int>(c, -1));
            }
            ans[0] = tmp;
            for (auto t : tmp) used[t] = true;

            for (int i = 1; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    ans[i][j] = find_not_used(ans[i - 1][j]);
                    used[ans[i][j]] = true;
                }
            }
        }
        return ans;
    }
};