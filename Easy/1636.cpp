class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> cnt;
        for (auto e : nums) cnt[e]++;
        sort(nums.begin(), nums.end(), [&](int a, int b) -> bool {
            if (cnt[a] == cnt[b]) return a > b;
            return cnt[a] < cnt[b];
        });
        return nums;
    }
};