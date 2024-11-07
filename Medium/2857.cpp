class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        int n = coordinates.size();
        unordered_map<long long, int> cnt;
        // map<vector<int>, int> cnt;
        long long tmp = 1ll * 1e7 * coordinates[0][0] + coordinates[0][1];
        cnt[tmp]++;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                // x1 xor x2 = j, y1 xor y2 = k - j
                // x2 = j xor x1, y2 = (k - j) xor y1
                tmp = 1ll * 1e7 * (j ^ coordinates[i][0]) + ((k - j) ^ coordinates[i][1]);
                ans += cnt[tmp];
            }
            tmp = 1ll * 1e7 * coordinates[i][0] + coordinates[i][1];
            cnt[tmp]++;
        }
        return ans;
    }
};