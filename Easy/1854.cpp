class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int cnt[3000];
        memset(cnt, 0, sizeof(cnt));
        for (auto ve : logs) {
            for (int i = ve[0]; i < ve[1]; i++) cnt[i]++;
        }
        int mx = -1;
        for (int i = 1950; i < 2050; i++) mx = max(mx, cnt[i]);
        for (int i = 1950; i < 2050; i++) if (cnt[i] == mx) return i;
        return -1;
    }
};