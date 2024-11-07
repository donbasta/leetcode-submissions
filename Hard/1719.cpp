class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        bitset<501> ve[501];
        int cnt[501];
        memset(cnt, false, sizeof(cnt));
        for (auto p : pairs) {
            cnt[p[0]]++, cnt[p[1]]++;
            ve[p[0]][p[1]] = true;
            ve[p[1]][p[0]] = true;
        }
        int nodes = 0;
        for (int i = 1; i <= 500; i++) nodes += cnt[i] > 0;
        if (*max_element(cnt, cnt + 501) != nodes - 1) return 0;

        bool dbl = false, cant = false;
        for (auto p : pairs) {
            if (!ve[p[0]][p[1]]) continue;
            ve[p[0]][p[1]] = false, ve[p[1]][p[0]] = false;
            if (ve[p[0]] == ve[p[1]]) dbl = true;
            if (((ve[p[0]] | ve[p[1]]) != ve[p[1]]) && ((ve[p[0]] | ve[p[1]]) != ve[p[0]])) cant = true;
            ve[p[0]][p[1]] = true, ve[p[1]][p[0]] = true;
        }
        if (cant) return 0;
        if (dbl) return 2;
        return 1;
    }
};