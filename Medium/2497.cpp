class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> tot(n);
        for (auto e : edges) {
            tot[e[0]].push_back(vals[e[1]]);
            tot[e[1]].push_back(vals[e[0]]);
        }
        for (int i = 0; i < n; i++) {
            sort(tot[i].begin(), tot[i].end(), greater<>());
        }
        const int INF = 2e9;
        int ret = -INF;
        for (int i = 0; i < n; i++) {
            int tmp = vals[i];
            for (int j = 0; j < tot[i].size(); j++) {
                if (j == k) break;
                if (tot[i][j] < 0) break;
                tmp += tot[i][j];
            }
            ret = max(ret, tmp);
        }
        return ret;
    }
};