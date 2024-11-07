class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (tx < sx || ty < sy || __gcd(sx, sy) != __gcd(tx, ty)) return false;
        if (sx == tx) return ((ty - sy) % sx == 0);
        if (sy == ty) return ((tx - sx) % sy == 0);
        if (ty > tx) return reachingPoints(sx, sy, tx, ty - tx);
        return reachingPoints(sx, sy, tx - ty, ty);
    }
};