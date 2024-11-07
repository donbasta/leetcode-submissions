class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        auto ok = [&](int x, int y) -> bool {
            string sx = to_string(nums[x]);
            string sy = to_string(nums[y]);
            int mx = max(sx.length(), sy.length());
            while (sx.length() < mx) sx = "0" + sx;
            while (sy.length() < mx) sy = "0" + sy;

            vector<vector<char>> ve;
            for (int i = 0; i < mx; i++) {
                if (sx[i] != sy[i]) {
                    ve.push_back(vector<char>{sx[i], sy[i]});
                }
            }
            if (ve.size() == 0) return true;
            if (ve.size() == 2) {
                if (ve[0][0] == ve[1][1] && ve[0][1] == ve[1][0]) return true;
            }
            return false;
        };

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (ok(i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};