class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int m = n / 2;
        vector<int> kiri(nums.begin(), nums.begin() + m);
        vector<int> kanan(nums.begin() + m, nums.end());
        int tot = 0;
        for (auto e : nums) tot += e;
        vector<vector<int>> left(m + 1), right(m + 1);
        for (int i = 0; i < (1 << m); i++) {
            int pop = __builtin_popcount(i);
            int tmp = 0;
            for (int j = 0; j < m; j++) {
                if ((i >> j) & 1) {
                    tmp += kiri[j];
                }
            }
            left[pop].push_back(tmp);
        }
        for (int i = 0; i < (1 << m); i++) {
            int pop = __builtin_popcount(i);
            int tmp = 0;
            for (int j = 0; j < m; j++) {
                if ((i >> j) & 1) {
                    tmp += kanan[j];
                }
            }
            right[pop].push_back(tmp);
        }
        for (int i = 0; i <= m; i++) {
            sort(left[i].begin(), left[i].end());
            sort(right[i].begin(), right[i].end());
        }
        const int INF = 2e9;
        int bestMin = -INF;
        for (int i = 0; i <= m; i++) {
            int pl = 0, pr = right[m - i].size() - 1;
            while (pl < left[i].size()) {
                while (pr >= 0 && 2 * (left[i][pl] + right[m - i][pr]) > tot) {
                    --pr;
                }
                if (pr < 0) break;
                bestMin = max(bestMin, left[i][pl] + right[m - i][pr]);
                ++pl;
            }
        }
        // cout << tot << ' ' << bestMin << '\n';
        return tot - 2 * bestMin;
    }
};