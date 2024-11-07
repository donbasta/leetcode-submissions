class Solution {
public:
    int lastRemaining(int n) {
        bool dir = true;
        int st = 1, dif = 1, cnt = n;
        while (cnt > 1) {
            if (dir) {
                st = st + dif;
            } else {
                if (cnt & 1) {
                    st = st + dif;
                }
            }
            cnt /= 2;
            dif *= 2;
            dir = !dir;
        }
        return st;
    }
};