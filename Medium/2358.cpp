class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        // 1 + 2 + ... + k + (sisa) = grades.size(), where sisa > k
        int n = grades.size();
        int l = 1, r = 1e3;
        while (l < r) {
            int m = (l + r + 1) >> 1;
            int cnt = m * (m + 1) / 2;
            if (cnt > n) {
                r = m - 1;
            } else {
                l = m;
            }
        }
        // 1 + 2 + ... + l <= n < 1 + 2 + ... + l + (l + 1) --> ans = l grup
        return l;
    }
};