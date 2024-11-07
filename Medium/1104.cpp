class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ret;
        int x = 32 - __builtin_clz(label);
        int cx = x;
        while (label) {
            int t = label;
            if ((cx - x) % 2 == 1) {
                t = 3 * (1 << (x - 1)) - 1 - label;
            }
            ret.push_back(t);
            label >>= 1;
            x--;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};