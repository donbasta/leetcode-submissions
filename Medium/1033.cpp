class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> pos = {a, b, c};
        sort(pos.begin(), pos.end());

        int mn, mx;
        if (pos[0] + 1 == pos[1] && pos[1] + 1 == pos[2]) {
            mx = mn = 0;
        } else if (pos[0] + 1 == pos[1] || pos[1] + 1 == pos[2]) {
            mn = 1;
            mx = max(pos[1] - 1 - pos[0], pos[2] - 1 - pos[1]);
        } else {
            if (pos[1] - pos[0] == 2 || pos[2] - pos[1] == 2) {
                mn = 1;
            } else {
                mn = 2;
            }
            mx = pos[2] - pos[0] - 2;
        }
        return vector<int>{mn, mx};
    }
};