class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n = points.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) -> bool {
            return max(abs(points[i][0]), abs(points[i][1])) < max(abs(points[j][0]), abs(points[j][1])); 
        });
        set<char> se;
        int la = -1;
        for (int i = 0; i < n; i++) {
            char cur = s[idx[i]];
            int len = 2 * max(abs(points[idx[i]][0]), abs(points[idx[i]][1]));
            if (se.count(cur)) {
                return (la + 1);
            }
            se.insert(cur);
            if (i < n - 1 && len < 2 * max(abs(points[idx[i + 1]][0]), abs(points[idx[i + 1]][1]))) {
                la = i;
            }
        }
        return n;
    }
};