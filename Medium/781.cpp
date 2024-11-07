class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> cnt;
        for (auto e : answers) cnt[e]++;
        int ans = 0;
        for (auto e : cnt) {
            ans += ((e.second + e.first) / (e.first + 1)) * (e.first + 1);
        }
        return ans;
    }
};