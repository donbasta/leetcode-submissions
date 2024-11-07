class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int aa = (a >> i) & 1;
            int bb = (b >> i) & 1;
            int cc = (c >> i) & 1;
            if (cc == 1 && aa == 0 && bb == 0) ans++;
            if (cc == 0) {
                if (aa == 1) ans++;
                if (bb == 1) ans++;
            }
        }
        return ans;
    }
};