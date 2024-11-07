class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int time = 0;
            for (auto p : piles) {
                time += (p + mid - 1) / mid;
                if (time > h) break;
            }
            if (time <= h) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};