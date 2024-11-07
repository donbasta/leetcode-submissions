class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int lo = 1, hi = position.back() - 1, piv;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int last = 0, cur = 1, cnt = 1;
            while (cur < n) {
                if (position[cur] - position[last] >= mid) {
                    last = cur;
                    cnt++;
                }
                cur++;
            }
            if (cnt >= m) {
                piv = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return piv;
    }
};