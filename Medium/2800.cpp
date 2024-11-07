class Solution {
public:
    string minimumString(string a, string b, string c) {
        vector<string> T = {a, b, c};
        vector<int> idx = {0, 1, 2};
        int mx = 1e8;
        string ret;

        auto merge = [&](string x, string y) -> string {
            if (x.find(y) != string::npos) {
                return x;
            }
            int lx = x.size(), ly = y.size();
            for (int i = min(lx, ly); i >= 1; i--) {
                if (x.substr(lx - i, i) == y.substr(0, i)) {
                    return x + y.substr(i, ly - i);
                }
            }
            return x + y;
        };

        do {
            string tmp = T[idx[0]];
            tmp = merge(tmp, T[idx[1]]);
            tmp = merge(tmp, T[idx[2]]);
            if ((int)tmp.length() < mx) {
                mx = tmp.length();
                ret = tmp;
            } else if ((int)tmp.length() == mx) {
                ret = min(ret, tmp);
            }
        } while (next_permutation(idx.begin(), idx.end()));
        return ret;
    }
};