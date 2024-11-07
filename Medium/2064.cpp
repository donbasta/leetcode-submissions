class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo = 1, hi = *max_element(quantities.begin(), quantities.end());
        int ret;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int need = 0;
            for (auto e : quantities) {
                need += (e / mid) + (e % mid != 0);
            }
            if (need <= n) {
                ret = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ret;
    }
};