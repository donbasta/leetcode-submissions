class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int len = to_string(nums[0]).length();
        int n = nums.size();
        using ll = long long;
        vector<vector<ll>> cnt(len, vector<ll>(10));
        for (int i = 0; i < n; i++) {
            string tmp = to_string(nums[i]);
            for (int j = 0; j < len; j++) {
                cnt[j][tmp[j] - '0']++;
            }
        }
        ll ret = 0;
        for (int i = 0; i < len; i++) {
            ll sum = 0, sum_sq = 0;
            for (int j = 0; j < 10; j++) {
                sum += cnt[i][j];
                sum_sq += cnt[i][j] * cnt[i][j];
            }
            ret += (sum * sum - sum_sq) / 2;
        }
        return ret;
    }
};