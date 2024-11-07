class Solution {
public:
    int numberOfChild(int n, int k) {
        int cur = 0;
        int dir = 1;
        for (int i = 0; i < k; i++) {
            if (cur + dir >= n || cur + dir < 0) dir *= -1;
            cur += dir;
        }
        return cur;
    }
};