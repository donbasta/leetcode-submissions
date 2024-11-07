class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<int>> adj1((int)edges1.size() + 1);
        vector<vector<int>> adj2((int)edges2.size() + 1);
        for (auto e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        } 

        auto dfs = [&](int root, vector<vector<int>>& E) -> vector<int> {
            int sz = E.size();
            vector<int> dis(sz);
            function<void(int, int)> trav = [&](int v, int p) {
                for (auto c : E[v]) {
                    if (c == p) continue;
                    dis[c] = dis[v] + 1;
                    trav(c, v);
                }
            };
            trav(root, root);
            return dis;
        };

        auto find_diam = [&](vector<vector<int>>& E) -> int {
            int sz = E.size();
            vector<int> dis = dfs(0, E);
            int mx = -1, arg_mx = -1;
            for (int i = 0; i < sz; i++) {
                if (dis[i] > mx) {
                    mx = dis[i];
                    arg_mx = i;
                }
            }
            dis = dfs(arg_mx, E);
            return *max_element(dis.begin(), dis.end());
        };

        int m = find_diam(adj1);
        int n = find_diam(adj2);
        return max({m, n, ((m + 1) / 2) + 1 + ((n + 1) / 2)});
    }
};