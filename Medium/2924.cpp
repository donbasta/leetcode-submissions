class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int winner = -1;
        vector<int> in(n);
        for (auto e : edges) {
            in[e[1]]++;
        }
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                if (winner != -1) {
                    return -1;
                } else {
                    winner = i;
                }
            }
        }
        return winner;
    }
};