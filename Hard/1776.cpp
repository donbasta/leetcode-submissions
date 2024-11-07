class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> ret(n, -1);
        int st = n - 1;
        vector<pair<int, int>> tmp;
        tmp.emplace_back(cars[st][0], cars[st][1]);

        auto right = [&](pair<int, int> x, pair<int, int> y, pair<int, int> z) {
            int dx1 = y.first - x.first, dy1 = y.second - x.second;
            int dx2 = z.first - y.first, dy2 = z.second - y.second;
            return (1ll * dx1 * dy2 - 1ll * dy1 * dx2) < 0ll;
        };

        for (int i = n - 2; i >= 0; i--) {
            if (cars[i][1] <= cars[st][1]) {
                tmp.clear();
                st = i;
                tmp.emplace_back(cars[i][0], cars[i][1]);
            } else {
                while (tmp.size() >= 2 && right(make_pair(cars[i][0], cars[i][1]), tmp.back(), tmp[tmp.size() - 2])) {
                    tmp.pop_back();
                }
                ret[i] = (double)(tmp.back().first - cars[i][0]) / (double)(cars[i][1] - tmp.back().second);
                tmp.emplace_back(cars[i][0], cars[i][1]);
            }
        }
        return ret;
    }
};