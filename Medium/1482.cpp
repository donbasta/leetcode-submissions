class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int lo = 1, hi = *max_element(bloomDay.begin(), bloomDay.end()), ans = -1;

        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int cur = 0;
            int tot = 0;
            for (int i = 0; i < n; i++) {
                if (bloomDay[i] > mid) {
                    cur = 0;
                } else {
                    cur++;
                    if (cur >= k) {
                        tot++;
                        cur = 0;
                    }
                }
            }
            if (tot >= m) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};