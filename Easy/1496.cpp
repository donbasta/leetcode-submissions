class Solution {
public:
    bool isPathCrossing(string path) {
        int cx = 0, cy = 0;
        set<pair<int, int>> vis;
        vis.emplace(0, 0);
        for (auto c : path) {
            if (c == 'N') cy++;
            else if (c == 'S') cy--;
            else if (c == 'W') cx--;
            else if (c == 'E') cx++;
            if (vis.count(make_pair(cx, cy))) return true;
            vis.emplace(cx, cy);
        }
        return false;
    }
};