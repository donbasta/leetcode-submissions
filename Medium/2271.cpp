class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        int n = tiles.size();
        vector<int> pref(n);
        pref[0] = tiles[0][1] - tiles[0][0] + 1;
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + (tiles[i][1] - tiles[i][0] + 1);
        }
        auto sum = [&](int a, int b) -> int {
            if (a > b) return 0;
            return (pref[b] - (a ? pref[a - 1] : 0));
        };
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int s = tiles[i][0];
            int e = s + carpetLen - 1;
            int idx = upper_bound(tiles.begin(), tiles.end(), vector<int>{e, INT_MAX}) - tiles.begin();
            ans = max(ans, sum(i, idx - 1) - max(0, tiles[idx - 1][1] - e));
        }
        return ans;
    }
};