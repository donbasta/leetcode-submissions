class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> adj(n);

        const function<bool(const string&, const string&)> equiv = [&](const string& ss, const string& tt) {
            vector<string> s(2), t(2);
            int ns = ss.length();
            for (int i = 0; i < ns; i++) {
                s[i & 1].push_back(ss[i]);
                t[i & 1].push_back(tt[i]);
            }
            for (int i = 0; i < 2; i++) {
                sort(s[i].begin(), s[i].end());
                sort(t[i].begin(), t[i].end());
            }
            return (s[0] == t[0] && s[1] == t[1]);
        };
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (equiv(words[i], words[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis(n);
        const function<void(int)> dfs = [&](int v) {
            for (auto c : adj[v]) {
                if (vis[c]) continue;
                vis[c] = true;
                dfs(c);
            }
        };
        int gr = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                gr++;
                vis[i] = true;
                dfs(i);
            }
        }
        return gr;
    }
};