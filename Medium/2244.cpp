class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> cnt;
        for (auto t : tasks) cnt[t]++;
        int ans = 0;
        for (auto e : cnt) {
            int b = e.second;
            if (b == 1) return -1;
            ans += (b + 2) / 3;
        }
        return ans;
    }
};