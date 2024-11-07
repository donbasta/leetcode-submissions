class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int le = 0, ri = n - 1;
        while (le <= ri) {
            int mid = (le + ri) >> 1;
            int mx = -1;
            vector<pair<int, int>> cand;
            for (int col = max(mid - 1, 0); col <= min(mid + 1, n - 1); col++) {
                for (int row = 0; row < m; row++) {
                    if (mat[row][col] > mx) {
                        mx = mat[row][col];
                        cand.clear();
                        cand.emplace_back(row, col);
                    } else if (mat[row][col] == mx) {
                        cand.emplace_back(row, col);
                    }
                }
            }
            for (auto c : cand) {
                if (c.second == mid) return vector<int>{c.first, c.second};
            }
            if (cand[0].second < mid) {
                ri = mid - 1;
            } else {
                le = mid + 1;
            }
        } 
        return {};
    }
};