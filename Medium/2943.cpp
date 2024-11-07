class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int lh = hBars.size(), lv = vBars.size();
        int mh = 0, mv = 0;
        int ch = 1, cv = 1;
        for (int i = lh - 2; i >= 0; i--) {
            if (hBars[i + 1] == hBars[i] + 1) {
                ch++;
            } else {
                mh = max(mh, ch);
                ch = 1;
            }
        }
        mh = max(mh, ch);
        for (int i = lv - 2; i >= 0; i--) {
            if (vBars[i + 1] == vBars[i] + 1) {
                cv++;
            } else {
                mv = max(mv, cv);
                cv = 1;
            }
        }
        mv = max(mv, cv);
        int side = min(mh, mv) + 1;
        return side * side;
    }
};