class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        int col[n];
        memset(col, -1, sizeof(col));
        auto op = [&](int x, int y) -> int {
            x = (x + y) % n;
            if (x < 0) x += n;
            return x;
        };
        for (int i = 0; i < n; i++) {
            if (col[i] != -1) continue;
            int cur = i;
            col[cur] = i;
            cur = op(cur, nums[cur]);
            while (col[cur] == -1) {
                col[cur] = i;
                cur = op(cur, nums[cur]);
            }
            if (col[cur] != i) continue;
            else {
                int start = cur;
                bool arah = (nums[cur] > 0);
                cur = op(cur, nums[cur]);
                int cnt = 1;
                bool ok = true;
                while (cur != start) {
                    cnt++;
                    ok &= ((nums[cur] > 0 == arah));
                    cur = op(cur, nums[cur]);
                }
                if (ok && (cnt > 1)) {
                    return true;
                }
            }
        }
        return false;
    }
};