class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> cnt;
        for (auto e : rectangles) {
            int a = e[0], b = e[1];
            int gcd = __gcd(a, b);
            a /= gcd, b /= gcd;
            cnt[make_pair(a, b)]++;
        }
        long long ret = 0;
        for (auto e : cnt) {
            ret += (1ll * e.second * (e.second - 1)) / 2;
        }
        return ret;
    }
};