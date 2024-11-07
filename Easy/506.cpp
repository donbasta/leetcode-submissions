class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> ve;
        for (int i = 0; i < n; i++) {
            ve.emplace_back(score[i], i);
        }
        sort(ve.begin(), ve.end(), greater<>());
        vector<string> ret(n);
        for (int i = 0; i < n; i++) {
            int pos = ve[i].second;
            if (i == 0) {
                ret[pos] = "Gold Medal";
            } else if (i == 1) {
                ret[pos] = "Silver Medal";
            } else if (i == 2) {
                ret[pos] = "Bronze Medal";
            } else {
                ret[pos] = to_string(i + 1);
            }
        }
        return ret;
    }
};