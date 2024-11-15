class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(60);
        for (auto t : time) {
            cnt[t % 60]++;
        }
        int ans = 0;
        for (int i = 1; i < 30; i++) {
            ans += cnt[i] * cnt[60  - i];
        }
        ans += 1ll * cnt[30] * (cnt[30] - 1) / 2;
        ans += 1ll * cnt[0] * (cnt[0] - 1) / 2;
        return ans;
    }
};