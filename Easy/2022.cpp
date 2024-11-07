class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> res;
        if (original.size() != m * n) return res;
        res.resize(m);
        for (int i = 0; i < m * n; i += n) {
            for (int j = i; j < i + n; j++) {
                res[i / n].push_back(original[j]);
            }
        }
        return res;
    }
};