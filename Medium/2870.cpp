class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto x : nums) {
            cnt[x]++;
        }
        int ans = 0;
        for (auto e : cnt) {
            int t = e.second;
            if (t == 1) return -1;
            if (t == 2 || t == 3) ans++;
            else if (t == 4) ans += 2;
            else if (t > 4) {
                ans += (t + 2) / 3;
            }
        }
        return ans;
    }
};