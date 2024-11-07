class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int sr = red, sb = blue;
        int ans = 0;
        for (int i = 1; ; i++) {
            if (i & 1) {
                if (sr < i) {
                    break;
                }
                sr -= i;
                ans = max(ans, i);
            } else {
                if (sb < i) {
                    break;
                }
                sb -= i;
                ans = max(ans, i);
            }
        }
        sr = red, sb = blue;
        for (int i = 1; ; i++) {
            if (i & 1) {
                if (sb < i) {
                    break;
                }
                sb -= i;
                ans = max(ans, i);
            } else {
                if (sr < i) {
                    break;
                }
                sr -= i;
                ans = max(ans, i);
            }
        }
        return ans;
    }
};