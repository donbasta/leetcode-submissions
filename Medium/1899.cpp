class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& tr, vector<int>& target) {
        sort(tr.begin(), tr.end());
        vector<int> cur(3);
        for (auto t : tr) {
            if (t[0] > target[0]) break;
            if (t[1] > target[1]) continue;
            if (t[2] <= target[2]) {
                cur[0] = max(cur[0], t[0]);
                cur[1] = max(cur[1], t[1]);
                cur[2] = max(cur[2], t[2]);
            }
        }
        // cout << cur[0] << ' ' << cur[1] << ' ' << cur[2] << '\n';
        return cur == target;
    }
};