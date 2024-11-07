class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        multiset<int> col, row, d1, d2;
        set<vector<int>> on;
        int sz = lamps.size();
        for (int i = 0; i < sz; i++) {
            if (on.count(lamps[i])) continue;
            row.insert(lamps[i][0]);
            col.insert(lamps[i][1]);
            d1.insert(lamps[i][1] - lamps[i][0]);
            d2.insert(lamps[i][1] + lamps[i][0]);
            on.insert(lamps[i]);
        }
        vector<int> ans;
        for (auto q : queries) {
            int r = q[0], c = q[1];
            bool ok = false;
            ok = (ok || row.count(r));
            ok = (ok || col.count(c));
            ok = (ok || d1.count(c - r));
            ok = (ok || d2.count(c + r));
            ans.push_back(ok);
            for (int x = r - 1; x <= r + 1; x++) {
                for (int y = c - 1; y <= c + 1; y++) {
                    if (x < 0 || x >= n || y < 0 || y >= n) continue;
                    if (!on.count(vector<int>{x, y})) continue;
                    on.erase(vector<int>{x, y});
                    row.erase(row.find(x));
                    col.erase(col.find(y));
                    d1.erase(d1.find(y - x));
                    d2.erase(d2.find(y + x));
                }
            }
        }
        return ans;
    }
};