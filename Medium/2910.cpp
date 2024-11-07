class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto e : nums) cnt[e]++;
        vector<int> freq;
        for (auto e : cnt) freq.emplace_back(e.second);
        sort(freq.begin(), freq.end());
        int sm = freq[0];
        int ans = nums.size();
        vector<int> ve(sm + 1);
        vector<bool> can(sm + 1, true);
        for (auto e : freq) {
            for (int i = 1; i <= sm; i++) {
                int q = e / i, r = e % i;
                if (r > q) {
                    can[i] = false;
                    continue;
                }
                ve[i] += q - ((q - r) / (i + 1));
            }
        }
        for (int i = 1; i <= sm; i++) {
            if (can[i]) {
                ans = min(ans, ve[i]);
            }
        }
        return ans;
    }
};