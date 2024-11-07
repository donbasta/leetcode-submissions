class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (citations.back() == 0) return 0;
        int l = 1, r = n;
        int ans;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (citations[n - mid] >= mid) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};