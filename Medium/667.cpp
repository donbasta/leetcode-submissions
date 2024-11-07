class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ret = {1};
        bool naik = true;
        for (int i = n - 1; i >= n - k + 1; i--) {
            int nx = ret.back();
            if (naik) {
                nx += i;
            } else {
                nx -= i;
            }
            ret.push_back(nx);
            naik ^= 1;
        }
        for (int i = k + 1; i <= n; i++) {
            int nx = ret.back();
            if (naik) {
                nx++;
            } else {
                nx--;
            }
            ret.push_back(nx);
        }
        return ret;
    }
};