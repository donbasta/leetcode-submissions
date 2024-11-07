class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> cnt(205);
        for (auto e : nums) cnt[e]++;
        int mx = -1;
        for (int i = 1; i <= 200; i++) mx = max(mx, cnt[i]);
        vector<vector<int>> ret(mx);
        for (int i = 1; i <= 200; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                ret[j].push_back(i);
            }
        }
        return ret;
    }
};