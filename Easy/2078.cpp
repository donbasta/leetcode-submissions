class Solution {
public:
    int maxDistance(vector<int>& colors) {
        vector<int> mn(101, 101), mx(101, -1);
        int n = colors.size();
        for (int i = 0; i < n; i++) {
            mn[colors[i]] = min(mn[colors[i]], i);
            mx[colors[i]] = max(mx[colors[i]], i);
        }
        int ans = 0;
        for (int i = 0; i <= 100; i++) {
            if (mx[i] == -1) continue;
            for (int j = 0; j <= 100; j++) {
                if (mx[j] == -1) continue;
                if (i == j) continue;
                ans = max(ans, abs(mx[j] - mn[i]));
                ans = max(ans, abs(mn[j] - mx[i]));
            }
        }
        return ans;
    }
};