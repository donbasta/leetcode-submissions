class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int, int> cnt;
        for (auto e : nums) {
            cnt[e]++;
        }
        int ans = 0;
        for (auto e : cnt) {
            ans += e.second / 2;
        }
        return vector<int>{ans, (int)nums.size() - 2 * ans};
    }
};