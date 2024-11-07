class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        map<int, int> mp[n];
        for (auto p : pick) {
            mp[p[0]][p[1]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int mx = 0;
            for (auto c : mp[i]) {
                mx = max(mx, c.second);
            }
            ans += (mx >= i + 1);
        }
        return ans;
    }
};