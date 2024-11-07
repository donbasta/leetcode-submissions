class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int attempts = minutesToTest / minutesToDie + 1;
        int cur = 1, ret = 0;
        while (cur < buckets) {
            cur *= attempts, ret++;
        }
        return ret;
    }
};