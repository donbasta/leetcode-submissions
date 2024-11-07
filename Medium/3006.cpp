class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int ns = s.length(), na = a.length(), nb = b.length();
        vector<int> A, B;
        for (int i = 0; i <= ns - na; i++) {
            if (s.substr(i, na) == a) {
                A.push_back(i);
            }
        }
        for (int i = 0; i <= ns - nb; i++) {
            if (s.substr(i, nb) == b) {
                B.push_back(i);
            }
        }
        vector<int> ret;
        for (auto e : A) {
            int j = lower_bound(B.begin(), B.end(), e) - B.begin();
            int tmp = INT_MAX;
            if (j < (int)B.size()) {
                tmp = min(tmp, B[j] - e);
            }
            if (j > 0) {
                tmp = min(tmp, e - B[j - 1]);
            }
            if (tmp <= k) {
                ret.push_back(e);
            }
        }
        return ret;
    }
};