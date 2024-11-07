class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto e : nums) cnt[e]++;
        int mx = 0;
        for (auto e : cnt) mx = max(mx, e.second);
        int ans = 0;
        for (auto e : cnt) if (e.second == mx) ans += mx;
        return ans;
    }
};