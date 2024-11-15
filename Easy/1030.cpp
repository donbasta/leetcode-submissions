class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ve;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ve.emplace_back(vector<int>{abs(i - rCenter) + abs(j - cCenter), i, j});
            }
        }
        sort(ve.begin(), ve.end());
        vector<vector<int>> ret;
        for (auto e : ve) {
            ret.push_back(vector<int>{e[1], e[2]});
        }
        return ret;
    }
};