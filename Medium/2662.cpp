class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& roads) {
        int n = roads.size();
        const int INF = 2e9;
        vector<vector<int>> dis(2 * n + 2, vector<int>(2 * n + 2, INF));

        auto get_dis = [&](int p, int q, int r, int s) -> int {
            return abs(p - r) + abs(q - s);
        };

        for (int i = 0; i < 2 * n + 2; i++) dis[i][i] = 0;
        dis[0][2 * n + 1] = dis[2 * n + 1][0] = get_dis(start[0], start[1], target[0], target[1]);
        for (int i = 0; i < n; i++) {
            dis[2 * i + 1][2 * i + 2] = min(roads[i][4], get_dis(roads[i][0], roads[i][1], roads[i][2], roads[i][3]));
            dis[2 * i + 2][2 * i + 1] = get_dis(roads[i][0], roads[i][1], roads[i][2], roads[i][3]);
            dis[0][2 * i + 1] = dis[2 * i + 1][0] = get_dis(start[0], start[1], roads[i][0], roads[i][1]);
            dis[0][2 * i + 2] = dis[2 * i + 2][0] = get_dis(start[0], start[1], roads[i][2], roads[i][3]);
            dis[2 * n + 1][2 * i + 1] = dis[2 * i + 1][2 * n + 1] = get_dis(target[0], target[1], roads[i][0], roads[i][1]);
            dis[2 * n + 1][2 * i + 2] = dis[2 * i + 2][2 * n + 1] = get_dis(target[0], target[1], roads[i][2], roads[i][3]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a1 = 2 * i + 1, a2 = 2 * i + 2, b1 = 2 * j + 1, b2 = 2 * j + 2;
                dis[a1][b1] = dis[b1][a1] = get_dis(roads[i][0], roads[i][1], roads[j][0], roads[j][1]);
                dis[a1][b2] = dis[b2][a1] = get_dis(roads[i][0], roads[i][1], roads[j][2], roads[j][3]);
                dis[a2][b1] = dis[b1][a2] = get_dis(roads[i][2], roads[i][3], roads[j][0], roads[j][1]);
                dis[a2][b2] = dis[b2][a2] = get_dis(roads[i][2], roads[i][3], roads[j][2], roads[j][3]);
            }
        }
        // cout << dis[0][2 * n + 1] << '\n';
        for (int k = 0; k < 2 * n + 2; k++) {
            for (int i = 0; i < 2 * n + 2; i++) {
                for (int j = 0; j < 2 * n + 2; j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        return dis[0][2 * n + 1];
    }
};