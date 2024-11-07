class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int lo = 0, hi = n - 1;
        int ans = -1;

        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            vector<int> diff;
            for (int i = 0; i < mid; i++) {
                if (heights[i + 1] > heights[i]) {
                    diff.push_back(heights[i + 1] - heights[i]);
                }
            }
            int sz = diff.size();
            sort(diff.begin(), diff.end());
            int rem = bricks;
            int ptr = 0;
            while (ptr < sz) {
                if (rem < diff[ptr]) break;
                rem -= diff[ptr];
                ptr++;
            }
            if (ladders >= sz - ptr) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};