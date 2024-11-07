class Solution {
public:
    vector<int> numOfBurgers(int t, int c) {
        // 4x + 2y = t
        // x + y = c
        // x = (t - 2c)/2
        // y = (4c - t)/2
        bool ok = (t % 2 ==0);
        ok &= (t >= c * 2);
        ok &= (t <= c * 4);
        if (!ok) {
            return vector<int>{};
        }
        return vector<int>{(t - 2 * c) / 2, (c * 4 - t) / 2};
    }
};