class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        for (int dx = -(n - 1); dx <= n - 1; dx++) {
            for (int dy = -(n - 1); dy <= n - 1; dy++) {
                int tmp = 0;
                for (int x = 0; x <= n - 1; x++) {
                    for (int y  = 0; y <= n - 1; y++) {
                        int nx = x + dx, ny = y + dy;
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                            tmp += (img1[nx][ny] == 1 && img2[x][y] == 1);
                        }
                    }
                }
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};