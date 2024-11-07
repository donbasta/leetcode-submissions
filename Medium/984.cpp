class Solution {
public:
    string strWithout3a3b(int a, int b) {
        int ca = 'a', cb = 'b';
        if (a > b) {
            swap(ca, cb);
            swap(a, b);
        }
        int t = b % (a + 1);
        int u = b / (a + 1);
        string ret;
        for (int j = 0; j < a; j++) {
            for (int i = 0; i < u; i++) ret.push_back(cb);
            if (t > 0) ret.push_back(cb);
            t--;
            ret.push_back(ca);
        }
        for (int i = 0; i < u; i++) ret.push_back(cb);
        assert (ret.size() == (a + b));
        return ret;
    }
};