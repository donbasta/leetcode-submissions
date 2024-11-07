class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int step = 1;
        vector<vector<bool>> yes(2, vector<bool>(4));
        yes[0][0] = yes[0][3] = yes[1][1] = yes[1][2] = true;
        while (step * (step + 1) / 2 < target) step++;
        while (!yes[target & 1][step % 4]) step++;
        return step;
    }
};