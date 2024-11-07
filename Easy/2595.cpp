class Solution {
public:
    vector<int> evenOddBit(int n) {
        int ret[2];
        ret[0] = ret[1] = 0;
        bool p = false;
        while (n) {
            if (n & 1) ret[p]++;
            n >>= 1, p = !p;
        }
        return vector<int>{ret[0], ret[1]};
    }
};