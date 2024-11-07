class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        int n = nums.size();
        map<vector<int>, vector<int>> ump;
        for (int i = 1; i <= n; i++) {
            int ni = i;
            vector<int> ve;
            for (int j = 2; j * j <= ni; j++) {
                if (ni % j != 0) continue;
                int pw = 0;
                while (ni % j == 0) {
                    ni /= j;
                    pw++;
                }
                if (pw & 1) {
                    ve.emplace_back(j);
                }
            }
            if (ni > 1) ve.emplace_back(ni);
            sort(ve.begin(), ve.end());
            ump[ve].push_back(i - 1);
        }
        long long ans = 0;
        for (auto x : ump) {
            long long tmp = 0;
            for (auto e : x.second) {
                tmp += nums[e];
            }
            ans = max(ans, tmp);
        }
        return ans;
    }
};