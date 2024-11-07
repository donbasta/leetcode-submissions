class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> cnt(3);
        for (auto s : stones) cnt[s % 3]++;
        int a = cnt[1], b = cnt[2];
        if (a < b) swap(a, b);
        bool ret = false;
        int x = cnt[0] & 1;

        if (b > 0) {
            ret = (ret || (x == 0));
        }
        if (a - b > 2) {
            ret = (ret || (x == 1));
        } else if (a - b == 0 && a > 0) {
            ret = (ret || (x == 0));
        }

        return ret;
    }
};