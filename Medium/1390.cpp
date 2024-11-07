class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        auto go = [&](int x) -> int {
            vector<pair<int, int>> pf;
            for (int i = 2; i * i <= x; i++) {
                if (x % i != 0) continue;
                int pw = 0;
                while (x % i == 0) {
                    pw++, x /= i;
                }
                pf.emplace_back(i, pw);
            }
            if (x > 1) pf.emplace_back(x, 1);
            if (pf.size() > 2) return 0;
            if (pf.size() == 2) {
                if (pf[0].second > 1 || pf[1].second > 1) return 0;
                int p = pf[0].first, q = pf[1].first;
                return 1 + p + q + p * q;
            }
            if (pf[0].second != 3) return 0;
            int p = pf[0].first;
            return 1 + p + p * p + p * p * p;
        };

        for (auto n : nums) {
            if (n <= 3) continue;
            ans += go(n);
        }
        return ans;
    }
};