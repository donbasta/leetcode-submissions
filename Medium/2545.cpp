class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<vector<int>> haha = score;
        sort(haha.begin(), haha.end(), [&](vector<int> a, vector<int> b) -> bool {
            return a[k] > b[k];
        });
        return haha;
    }
};