class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 1) return 0;
        int MX, mx, prvMx, lol;
        int ans = 0;
        {
            mx = 0, prvMx = -1, lol = 0;
            for (int i = 0; i < n; i++) {
                if (height[i] > mx) {
                    ans += (mx * (i - prvMx) - lol);
                    mx = height[i];
                    prvMx = i;
                    lol = 0;
                }
                lol += height[i];
            }
        }
        {
            mx = 0, prvMx = n, lol = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (height[i] > mx) {
                    ans += (mx * (prvMx - i) - lol);
                    mx = height[i];
                    prvMx = i;
                    lol = 0;
                }
                lol += height[i];
            }
            MX = mx;
        }
        int le = -1, ri = -1;
        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + height[i];
            if (height[i] == MX) {
                if (le == -1) le = i;
                ri = i;
            }
        }
        if (le != ri) {
            ans += ((ri - le - 1) * MX - (pre[ri] - pre[le + 1]));
        }
        return ans;
    }
};