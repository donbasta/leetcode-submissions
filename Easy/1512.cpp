class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> cnt(101);
        int ans = 0;
        for (auto e : nums) { ans += cnt[e], cnt[e]++; }
        return ans;
    }
};