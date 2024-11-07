class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto e : nums) {
            if (e % 2 == 0) cnt[e]++;
        }
        int mx = 0;
        int ans = -1;
        for (auto e : cnt) {
            if (e.second == mx) {
                ans = min(e.first, ans);
            } else if (e.second > mx) {
                ans = e.first;
                mx = e.second;
            }
        }
        return ans;
    } 
};