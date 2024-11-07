class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> nx(n);
        vector<int> in(n), rem;
        for (auto e : invocations) {
            nx[e[0]].push_back(e[1]);
            in[e[1]]++;
        }

        vector<bool> vis(n);
        queue<int> Q;   
        rem.push_back(k);
        vis[k] = true;
        Q.push(k);
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            for (auto c : nx[now]) {
                --in[c];
                if (vis[c]) continue;
                rem.push_back(c);
                vis[c] = true;
                Q.push(c);
            }
        }

        vector<bool> out(n);
        for (auto r : rem) {
            if (in[r] > 0) {
                vector<int> ans;
                for (int i = 0; i < n; i++) ans.push_back(i);
                return ans;
            }
            out[r] = true;
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (out[i]) continue;
            ans.push_back(i);
        }
        return ans;
    }
};