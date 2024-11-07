class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<int> H, V;
        for (auto r : rectangles) {
            H.push_back(r[0]);
            H.push_back(r[2]);
            V.push_back(r[1]);
            V.push_back(r[3]);
        }
        sort(H.begin(), H.end());
        H.resize(unique(H.begin(), H.end()) - H.begin());
        sort(V.begin(), V.end());
        V.resize(unique(V.begin(), V.end()) - V.begin());
        int sh = H.size(), sv = V.size();
        int T[sh][sv];
        memset(T, 0, sizeof(T));

        for (auto r : rectangles) {
            int y1 = lower_bound(V.begin(), V.end(), r[1]) - V.begin();
            int y2 = lower_bound(V.begin(), V.end(), r[3]) - V.begin();
            int x1 = lower_bound(H.begin(), H.end(), r[0]) - H.begin();
            int x2 = lower_bound(H.begin(), H.end(), r[2]) - H.begin();

            for (int i = x1 + 1; i <= x2; i++) {
                T[i][y1]--, T[i][y2]++;
            }
        }
        for (int i = 1; i < sh; i++) {
            for (int j = sv - 2; j >= 0; j--) {
                T[i][j] += T[i][j + 1];
            }
        }
        int area = 0;
        const int MOD = 1e9 + 7;
        for (int i = 1; i < sh; i++) {
            for (int j = 1; j < sv; j++) {
                if (T[i][j] > 0) {
                    int p = H[i] - H[i - 1];
                    int q = V[j] - V[j - 1];
                    area = (1ll * p * q + area) % MOD;
                }
            }
        }

        return area;
    }
};