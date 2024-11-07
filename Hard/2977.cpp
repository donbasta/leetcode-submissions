class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        unordered_map<string, int> mp;
        vector<string> tmp = original;
        for (auto e : changed) tmp.push_back(e);
        sort(tmp.begin(), tmp.end());
        tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin()); 
        int idx = 0;
        for (auto c : tmp) mp[c] = idx++;
    
        const long long INF = 1e15;
        long long dp[idx][idx];
        for (int i = 0; i < idx; i++) for (int j = 0; j < idx; j++) dp[i][j] = INF;
        int n = cost.size();
        for (int i = 0; i < idx; i++) dp[i][i] = 0;
        for (int i = 0; i < n; i++) {
            int u = mp[original[i]], v = mp[changed[i]];
            dp[u][v] = min(dp[u][v], 1ll * cost[i]);
        }
        for (int i = 0; i < idx; i++) {
            for (int j = 0; j < idx; j++) {
                for (int k = 0; k < idx; k++) {
                    dp[j][k] = min(dp[j][i] + dp[i][k], dp[j][k]);
                }
            }
        }

        vector<int> lens;
        for (auto& v : original) {
            lens.push_back(v.size());
        }
        sort(lens.begin(), lens.end());
        lens.erase(unique(lens.begin(), lens.end()), lens.end());

        int len = source.size();
        long long f[len + 1];
        for (int i = 0; i <= len; i++) f[i] = INF;
        f[len] = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (source[i] == target[i]) {
                f[i] = f[i + 1];
            }
            for (int l : lens) {
                if (i + l - 1 < len) {
                    string sx = source.substr(i, l);
                    string tx = target.substr(i, l);
                    if (!mp.count(sx) || !mp.count(tx)) continue;
                    if (dp[mp[sx]][mp[tx]] == INF) continue;
                    if (f[i + l] != INF) {
                        f[i] = min(f[i], dp[mp[sx]][mp[tx]] + f[i + l]);
                    }
                }   
            }
        }
        if (f[0] == INF) return -1;
        return f[0];
    }
};