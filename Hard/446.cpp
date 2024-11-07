class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long, int>> ve(n);
        for (int i = 2; i < n; i++) {
            unordered_map<long long, int> cnt;
            for (int j = 0; j < i; j++) {
                long long sel = 1ll * nums[i] - nums[j];
                long long cari = 1ll * nums[j] - sel;
                ve[i][sel] += ve[j][sel];
                ve[i][sel] += cnt[cari];
                cnt[nums[j]]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (auto e : ve[i]) {
                ans += e.second;
            }
        }
        return ans;
    }
};