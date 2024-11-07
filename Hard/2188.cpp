class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        const int M = 30;
        const int INF = 1e9;
        vector<int> best(M + 1, INF);
        for (auto t : tires) {
            int f = t[0], r = t[1];
            int w = 1;
            int sum = f;
            int mul = 1;
            while (true) {
                // cout << w << ' ' << sum << ' ' << best[w] << '\n';
                best[w] = min(best[w], sum);
                if (1ll * mul * r >= 1ll * INF) break;
                mul *= r;
                if (1ll * sum + 1ll * f * mul >= 1ll * INF) break;
                sum += f * mul;
                w++;
            }
        }
        vector<int> DP(numLaps + 1, INF);
        DP[0] = 0;
        for (int i = 1; i <= numLaps; i++) {
            for (int j = 1; j <= M; j++) {
                if (best[j] == INF) break;
                if (i >= j) {
                    DP[i] = min(DP[i], DP[i - j] + best[j] + changeTime);
                }
            }
        }
        return DP[numLaps] - changeTime;
    }
};