class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int m = firstList.size(), n = secondList.size();
        int i = 0, j = 0;
        vector<vector<int>> res;
        while (i < m && j < n) {
            int l1 = firstList[i][0], r1 = firstList[i][1];
            int l2 = secondList[j][0], r2 = secondList[j][1];
            if (max(l1, l2) <= min(r1, r2)) {
                res.push_back({max(l1, l2), min(r1, r2)});
            }
            if (r1 == r2) {i++, j++;}
            else if (r1 > r2) {j++;}
            else if (r1 < r2) {i++;}
        }
        return res;
    }
};