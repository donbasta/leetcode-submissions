class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<int> pos[101];
        for (auto r : rectangles) {
            pos[r[1]].push_back(r[0]);
        }
        for (int i = 1; i <= 100; i++) {
            sort(pos[i].begin(), pos[i].end());
        }
        int sz = points.size();
        vector<int> ans(sz);
        for (int i = 0; i < sz; i++) {
            int x = points[i][0], y = points[i][1];
            int tmp = 0;
            for (int j = y; j <= 100; j++) {
                tmp += pos[j].size() - (lower_bound(pos[j].begin(), pos[j].end(), x) - pos[j].begin());
            }
            ans[i] = tmp;
        }
        return ans;
    }
};