class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int lo = 0, hi = price.back() - price[0];
        int ans = -1;

        auto ok = [&](int x) -> bool {
            int cur = price[0];
            int cnt = 1;
            for (int i = 1; i < price.size(); i++) {
                if (price[i] - cur >= x) {
                    cnt++;
                    cur = price[i];
                }
            }
            return cnt >= k;
        };

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (ok(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};