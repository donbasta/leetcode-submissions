class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        const int M = 1e5;
        vector<vector<int>> diag(M + 5);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                diag[i + j].push_back(nums[i][j]);
            }
        }
        vector<int> res;
        for (int i = 0; i <= M; i++) {
            if (diag[i].empty()) break;
            reverse(diag[i].begin(), diag[i].end());
            for (auto e : diag[i]) {
                res.push_back(e);
            }
        }
        return res;
    }
};