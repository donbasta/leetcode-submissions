class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        vector<int> cnt(2);
        for (auto p : position) {
            cnt[p & 1]++;
        }
        return min(cnt[0], cnt[1]);
    }
};