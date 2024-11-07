class Solution {
public:
    vector<int> rec(int n) {
        if (n == 1) {
            return {0, 1};
        }
        vector<int> hehe = rec(n - 1);
        vector<int> ret;
        int cari = (1 << (n - 1)) - 1;
        int sz = hehe.size();
        for (int i = 0; i < sz; i++) {
            ret.push_back(hehe[i]);
            if (hehe[i] == cari) {
                int cnt = 0;
                for (int j = i; cnt < sz; j = (j + sz - 1) % sz) {
                    ret.push_back(hehe[j] + (1 << (n - 1)));
                    cnt++;
                }
            }
        }
        return ret;
    }

    vector<int> circularPermutation(int n, int start) {
        vector<int> hehe = rec(n);
        vector<int> ret;
        int mulai = 0;
        for (int i = 0; i < hehe.size(); i++) {
            if (hehe[i] == start) {
                mulai = i;
                break;
            }
        }
        int sz = (1 << n);
        assert (sz == hehe.size());
        for (int i = mulai; ret.size() < sz ; i = (i + 1) % sz) {
            ret.push_back(hehe[i]);
        }
        return ret;
    }
};