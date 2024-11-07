class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n = stockPrices.size();
        if (n == 1) return 0;
        if (n == 2) return 1;
        sort(stockPrices.begin(), stockPrices.end(), [&](vector<int>& x, vector<int>& y) -> bool {
            return x[0] < y[0];
        });

        auto get_dir = [&](vector<int>& p1, vector<int>& p2) -> pair<int, int> {
            int dx = p2[0] - p1[0];
            int dy = p2[1] - p1[1];
            int fpb = __gcd(abs(dx), abs(dy));
            dx /= fpb, dy /= fpb;
            return make_pair(dx, dy); 
        };

        pair<int, int> cur_dir = get_dir(stockPrices[0], stockPrices[1]);
        // cout << cur_dir.first << ' ' << cur_dir.second << '\n';
        int ret = 1; 
        int st = 0;
        for (int i = 2; i < n; i++) {
            if (get_dir(stockPrices[st], stockPrices[i]) != cur_dir) {
                // cout << i << ' ';
                ret++;
                st = i - 1;
                cur_dir = get_dir(stockPrices[i - 1], stockPrices[i]);
            }
        }
        return ret;
    }
};