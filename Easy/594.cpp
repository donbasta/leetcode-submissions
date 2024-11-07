class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto e : nums) cnt[e]++;
        int ans = 0;
        for (auto e : cnt) {
            if (cnt.find(e.first - 1) != cnt.end()) ans = max(ans, e.second + cnt[e.first - 1]);
            if (cnt.find(e.first + 1) != cnt.end()) ans = max(ans, e.second + cnt[e.first + 1]);
        }
        return ans;
    }
};