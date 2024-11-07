class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        const int B = 30;
        int ans = 0;
        for (int i = 0; i < B; i++) {
            int cnt[2];
            cnt[0] = cnt[1] = 0;
            for (auto e : nums) {
                cnt[(e >> i) & 1]++;
            }
            ans += cnt[0] * cnt[1];
        }
        return ans;
    }
};