class Solution {
public:
    int maxJump(vector<int>& stones) {
        int l = 1, r = stones.back(), piv = -1;
        int n = stones.size();

        auto ok = [&](int leap) -> bool {
            int cur = 0, nx = 0;
            vector<bool> vis(n);
            while (cur < n - 1) {
                // cout << "naik: " << leap << ' ' << cur << '\n';
                int farthest = stones[cur] + leap;
                while (nx < n && stones[nx] <= farthest) nx++;
                if (nx - 1 == cur) return false;
                vis[nx - 1] = true;
                cur = nx - 1;
                nx = nx - 1;
            }
            while (cur > 0) {
                // cout << "turun: " << leap << ' ' << cur << '\n';
                int farthest = stones[cur] - leap;
                while (nx >= 0 && stones[nx] >= farthest) nx--;
                nx++;
                while (nx < cur && vis[nx]) nx++;
                if (nx == cur) return false;
                cur = nx;
            }
            return true;
        };

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (ok(mid)) {
                piv = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return piv;
    }
};