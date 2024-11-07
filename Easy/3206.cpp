class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int prv = (i + n - 1) % n;
            int nx = (i + 1) % n;
            if ((colors[prv] != colors[i]) && (colors[i] != colors[nx])) {
                ans++;
            }
        }
        return ans;
    }
};