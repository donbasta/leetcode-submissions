class Solution {
public:
    const int mod = 1e9 + 7;

    int fpow(int a, int b) {
        int ret = 1;
        while (b) {
            if (b & 1) ret = (1ll * ret * a) % mod;
            a = (1ll * a * a) % mod;
            b >>= 1;
        }
        return ret;
    }
    
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        int l = ranges[0][0], r = ranges[0][1];
        int n = ranges.size();
        int size = 1;
        for (int i = 1; i < n; i++) {
            if (ranges[i][0] > r) {
                size++;
                l = ranges[i][0], r = ranges[i][1];
            } else {
                r = max(r, ranges[i][1]);
            }
        }
        return fpow(2, size);
    }
};