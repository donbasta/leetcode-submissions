class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int ret = 1;
        int n = position.size();
        int idx[n];
        iota(idx, idx + n, 0);
        sort(idx, idx + n, [&](int a, int b) -> bool {
            return position[a] > position[b];
        });

        auto meet = [&](int x, int y) -> bool {
            int p1 = position[idx[x]], p2 = position[idx[y]];
            int s1 = speed[idx[x]], s2 = speed[idx[y]];
            if (s2 <= s1) return false;
            return (1ll * p1 * s2 - 1ll * p2 * s1) <= 1ll * target * (s2 - s1);
        };

        int start_fleet_index = 0;
        for (int i = 1; i < n; i++) {
            if (!meet(start_fleet_index, i)) {
                start_fleet_index = i;
                ret++;
            }
        }
        return ret;

        // p1 + s1 * t = p2 + s2 * t <= target
        // t = (p1 - p2) / (s2 - s1);
        // (p1s2 - s1p2) / (s2 - s1) <= target
    }
};