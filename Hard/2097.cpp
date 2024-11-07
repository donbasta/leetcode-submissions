class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> nx;
        unordered_map<int, int> out, in;
        for (auto e : pairs) {
            nx[e[0]].push_back(e[1]);
            out[e[0]]++;
            in[e[1]]++;
        }
        int start = pairs[0][0];
        for (auto e : out) {
            if (out[e.first] - in[e.first] == 1) {
                start = e.first;
                break;
            }
        }
        int n = pairs.size();
        int route[n + 1];
        int id = n;
        const function<void(int)> dfs = [&](int v) {
            while (out[v]) {
                int next = nx[v][--out[v]];
                dfs(next);
            }
            route[id--] = v;
        };
        dfs(start);
        vector<vector<int>> ret;
        for (int i = 1; i <= n; i++) {
            ret.push_back({route[i - 1], route[i]});
        }
        return ret;
    }
};