class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> sum(3);
        vector<vector<int>> ve(3);
        for (auto e : nums) {
            sum[e % 3] += e;
            ve[e % 3].push_back(e);
        }
        for (int i = 0; i < 3; i++) {
            sort(ve[i].begin(), ve[i].end());
        }
        int tot = sum[0] + sum[1] + sum[2];
        if (tot % 3 == 0) {
            return tot;
        } else if (tot % 3 == 1) {
            int kur = INT_MAX;
            if (ve[1].size() > 0) kur = min(kur, ve[1][0]);
            if (ve[2].size() > 1) kur = min(kur, ve[2][1] + ve[2][0]);
            assert (kur < INT_MAX);
            return tot - kur;
        }
        int kur = INT_MAX;
        if (ve[2].size() > 0) kur = min(kur, ve[2][0]);
        if (ve[1].size() > 1) kur = min(kur, ve[1][1] + ve[1][0]);
        assert (kur < INT_MAX);
        return tot - kur;
    }
};