class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret(n);
        iota(ret.begin(), ret.end(), 1);
        sort(ret.begin(), ret.end(), [&](int a, int b) -> bool {
            return to_string(a) < to_string(b);
        });
        return ret;
    }
};