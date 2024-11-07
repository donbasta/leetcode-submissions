class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        bool ok = true;
        int n = matrix.size();
        for (auto m : matrix) {
            set<int> se;
            for (auto c : m) se.insert(c);
            ok &= (se.size() == n);
        }
        for (int i = 0; i < n; i++) {
            set<int> se;
            for (int j = 0; j < n; j++) {
                se.insert(matrix[j][i]);
            }
            ok &= (se.size() == n);
        }
        return ok;
    }
};