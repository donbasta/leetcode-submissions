class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int dir_idx = 0;
        int px = 0, py = 0;
        for (int i = 0; i < 4; i++) {
            for (auto c : instructions) {
                if (c == 'G') {
                    px += dx[dir_idx], py += dy[dir_idx];
                } else if (c == 'L') dir_idx = (dir_idx + 3) % 4;
                else dir_idx = (dir_idx + 1) % 4;
            }
        }
        return px == 0 && py == 0;
    }
};