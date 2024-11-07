class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (auto e : nums) cnt[e]++;
        int ans = 0;
        for (auto e : cnt) {
            if (k == 0) ans += (e.second >= 2);
            else ans += (cnt.find(e.first + k) != cnt.end()); 
        }
        return ans;
    }
};