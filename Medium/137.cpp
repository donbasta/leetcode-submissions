class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto e : nums) cnt[e]++;
        for (auto e : cnt) {
            if (e.second == 1) return e.first;
        }
        assert(false);
        return -1;
    }
};