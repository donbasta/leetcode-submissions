class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        int F[] = {1, 1, 2, 0, 0, 2, 2, 0, 1, 2};
        auto ok = [&](int x) -> bool {
            string st = to_string(x);
            int cnt = 0;
            for (auto c : st) {
                if (F[c - '0'] == 0) return false;
                if (F[c - '0'] == 2) cnt++;
            }
            return cnt > 0;
        };

        for (int i = 1; i <= n; i++) {
            ans += ok(i);
        }
        return ans;
    }
};