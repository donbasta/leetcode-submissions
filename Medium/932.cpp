class Solution {
public:
    vector<int> beautifulArray(int n) {
        if (n == 1) return {1};
        if (n == 2) return {1, 2};
        vector<int> l = beautifulArray(n / 2);
        vector<int> r = l;
        if (n & 1) {
            r = beautifulArray(n / 2 + 1);
        }
        vector<int> ret;
        for (auto e : l) ret.push_back(2 * e);
        for (auto e : r) ret.push_back(2 * e - 1);
        return ret;
    }
};