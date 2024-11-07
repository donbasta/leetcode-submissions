class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        set<int> occupiedRows;
        map<int, map<int, bool>> hehe;
        for (auto e : reservedSeats) {
            occupiedRows.insert(e[0]);
            hehe[e[0]][e[1]] = true;
        }
        int ans = 2 * (n - occupiedRows.size());
        for (auto e : occupiedRows) {
            vector<int> T(10), pre(10);
            for (auto [p, _] : hehe[e]) {
                T[p - 1] = true;
            }
            for (int i = 0; i < 10; i++) {
                pre[i] = T[i] + (i ? pre[i - 1] : 0);
            }
            if (pre[8] - pre[0] == 0) ans += 2;
            else if (pre[8] - pre[4] == 0) ans++;
            else if (pre[4] - pre[0] == 0) ans++;
            else if (pre[6] - pre[2] == 0) ans++;
        }
        return ans;
    }
};