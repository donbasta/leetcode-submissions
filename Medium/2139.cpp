class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int step = 0;
        while (target > 1) {
            if (maxDoubles == 0) {
                step += (target - 1);
                break;
            }
            if (target & 1) {
                target--;
                step++;
            }
            target /= 2;
            step++;
            maxDoubles--;
        }
        return step;
    }
};