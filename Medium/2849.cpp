class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x = max(abs(sx - fx), abs(sy - fy));
        if (x == 0 && t == 1) return false;
        return (x <= t);
    }
};