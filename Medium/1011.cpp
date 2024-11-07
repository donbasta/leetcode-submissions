class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int d = 0;
            int tmp = 0;
            for (int i = 0; i < weights.size(); i++) {
                if (tmp + weights[i] > mid) {
                    d++;
                    tmp = weights[i];
                } else {
                    tmp += weights[i];
                }
            }
            d++;
            if (d <= days) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        assert (ans != -1);
        return ans;
    }
};