class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        set<int> C;
        for (auto e : points) C.insert(e[0]);
        unordered_map<int, int> cmp;
        int tmp = 0;
        for (auto e : C) cmp[e] = tmp++;

        vector<vector<int>> cols(tmp);
        const int INF = 2e9;
        for (auto e : points) {
            cols[cmp[e[0]]].push_back(e[1]);
        }
        for (auto& e : cols) {
            sort(e.begin(), e.end());
        }
        int ans = 0;
        for (auto e : points) {
            int ic = cmp[e[0]], ub = INF;
            for (int i = ic; i >= 0; i--) {
                int x;
                if (i == ic) {
                    x = upper_bound(cols[i].begin(), cols[i].end(), e[1]) - cols[i].begin();
                } else {
                    x = lower_bound(cols[i].begin(), cols[i].end(), e[1]) - cols[i].begin();
                }
                if (x == cols[i].size()) continue;
                if (cols[i][x] >= ub) continue;
                ub = cols[i][x];
                ans++;
            } 
        }
        return ans;


    }
};