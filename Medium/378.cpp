class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int lo = -1e9, hi = 1e9;
        int n = matrix.size();
        int ans;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int tmp = 0;
            for (int i = 0; i < n; i++) {
                tmp += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (tmp >= k) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};